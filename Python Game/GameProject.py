from secrets import choice
import time
import random
import json
import os

data ={}

def save_data():
    with open("game_data.json","w") as f:
        json.dump(data,f)

def read_data():
    global data
    with open("game_data.json","r") as f:
        data=json.load(f)

read_data()

class Creator():
    def __init__(self,life,defense,damage):
        self.level = 1
        self.experience=0
        self.boss_level=1
        self.life=life
        self.defense=defense
        self.damage=damage
        self.critical=10
        self.penetrating =15

    def attack(self,user):
        if random.randint(1,100) <= self.critical:
            if random.randint(1,100) <= self.penetrating:
                user.life-=self.damage*2
            else:
                user.life-=(self.damage - user.defense)*2
        else:
            if random.randint(1,100) <= self.penetrating:
                user.life-=self.damage*2
            else:
                user.life-=self.damage - user.defense
        
hero=Creator(data["life"],data["defense"],data["damage"])
hero.level=data["level"]
hero.experience=data["experience"]
hero.boss_level=data["boss_level"]
hero.critical=data["critical"]
hero.penetrating=data["penetrating"]

creature=Creator(40,10,20)

def show(a):
    print(f"""
Life:         {a.life}
Defense:      {a.defense}
Damage:       {a.damage}
Critical:     {a.critical}
Penetration:  {a.penetrating}""")


def attack_boss():
    boss=Creator(100+10*hero.boss_level,20+2*hero.boss_level, 35+3*hero.boss_level)
    print("Hero: ")
    show(hero)
    print("\nBoss: ")
    show(boss)
    hero_life=hero.life
    version=int(input("""
1 Show the details
2 Don't show the details"""))
    if version==1:
        while True:
            input("Press enter to attack")
            time.sleep(2)
            hero.attack(boss)
            if boss.life<=0:
                print("Boss is dead, You won.")
                hero.life=hero_life+10
                hero.damage+=2
                hero.defense+=2
                hero.critical+=1
                hero.penetrating+=1
                hero.boss_level+=1
                data["damage"]+=2
                data["defense"]+=2
                data["critical"]+=1
                data["penetrating"]+=1
                data["boss_level"]+=1
                save_data()
                break
           
            print(f"Boss has {boss.life} life. ")
            time.sleep(1)
            print("Now the boss is attacking you.")
            time.sleep(2)
            boss.attack(hero)
            if hero.life<=0:
                print("You are dead, You lost.")
                hero.life=hero_life
                break
            print(f"You have {hero.life} life.")
    elif version==2:
        while True:
            hero.attack(boss)
            if boss.life<=0:
                print("Boss is dead, You won.")
                hero.life=hero_life+10
                hero.damage+=2
                hero.defense+=2
                hero.critical+=1
                hero.penetrating+=1
                hero.boss_level+=1
                data["damage"]+=2
                data["defense"]+=2
                data["critical"]+=1
                data["penetrating"]+=1
                data["boss_level"]+=1
                save_data()
                break
            boss.attack(hero)
            if hero.life<=0:
                print("You are dead, You lost.")
                hero.life=hero_life
                break
            print(f"You have {hero.life} life.")
    if hero.boss_level >100:
        print("GAME OVER")


def increase_level():
    hero.level+=1
    data["level"]+=1
    save_data()
    print(f"Your level is {hero.level}.")
    print("""
1 Life
2 Defense
3 Damage
4 Critical
5 Penetration""")
    option=int(input("Which one would you like to upgrade?"))
    
    if option==1:
        hero.life+=10
        data["life"]+=10
        save_data()
        print(f"Now you have {hero.life} life.")
    elif option==2:
        hero.defense+=2
        data["defense"]+=2
        save_data()
        print(f"Now you have {hero.defense} defense.")
    elif option==3:
        hero.damage+=2
        data["damage"]+=2
        save_data()
        print(f"Now you have {hero.damage} damage.")
    elif option==4:
        hero.critical+=1
        data["critical"]+=1
        save_data()
        print(f"Now you have {hero.critical} critical chance.")
    elif option==5:
        hero.penetrating+=1
        data["penetrating"]+=1
        save_data()
        print(f"Now you have {hero.penetrating} penetration chace.")

def attack_creature():
    creature_nr = int(input("How many creatures you want to attack?"))
    no_exp=creature_nr
    hero_life=hero.life
    hero_defense=hero.defense
    version=int(input("""
1 Show the details
2 Don't show the details"""))
    if hero_defense>=40:
        hero.defense=30
    if version==1:
        while True:
            input("Press enter to attack")
            time.sleep(2)
            hero.attack(creature)
            if creature.life<=0 and creature_nr==1:
                print("Creature is dead, You won.")
                hero.experience+=no_exp*50
                data["experience"]+=no_exp*50
                save_data()
                hero.life=hero_life
                hero.defense=hero_defense
                if hero.experience>=hero.level*100:
                    increase_level()
                    hero.experience=0
                    data["experience"]=0
                    save_data()

                break
            elif creature.life<=0 and creature_nr>1:
                creature_nr-=1
                print(f"You killed one creature and there are {creature_nr} creatures left.")
                creature.life=40
            print(f"Creature has {creature.life} life. ")
            time.sleep(1)
            print("Now creatures are attacking you.")
            time.sleep(2)
            for i in range(creature_nr):
                creature.attack(hero)
            if hero.life<=0:
                print("You are dead, You lost.")
                hero.life=hero_life
                hero.defense=hero_defense
                break
            print(f"You have {hero.life} life.")
    elif version==2:
        while True:
            hero.attack(creature)
            if creature.life<=0 and creature_nr==1:
                print("Creature is dead, You won.")
                hero.experience+=no_exp*50
                data["experience"]+=no_exp*50
                save_data()
                hero.life=hero_life
                hero.defense=hero_defense
                if hero.experience>=hero.level*100:
                    increase_level()
                    hero.experience=0
                    data["experience"]=0
                    save_data()
                break
            elif creature.life<=0 and creature_nr>1:
                creature_nr-=1
                creature.life=40
            for i in range(creature_nr):
                creature.attack(hero)
            if hero.life<=0:
                print("You are dead, You lost.")
                hero.life=hero_life
                hero.defense=hero_defense
                break
            
            
        
def main():
    while True:
        print("""
    1 Attack Creatures 
    2 Attack Boss
    3 Exit""")
        choice=int(input("What do you want to do?"))
        os.system('cls' if os.name == 'nt' else 'clear')
        if choice==1:
            attack_creature()
        elif choice==2:
            attack_boss()
        elif choice==3:
            break


main() 