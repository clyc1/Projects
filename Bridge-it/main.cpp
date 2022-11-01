#include <iostream>
#include <fstream>
#include <graphics.h>
#include <winbgim.h>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

using namespace std;

ofstream fout("proiect.out");
int nr_x_ex=4,nr_y_ex,matxy,c=0,w[21][21],xa[100][100],nrnod=0,startgame=0,x_x,y_y,x_x1,x_x2,y_y1,y_y2,dim,patrat_p1=0,patrat_p2=0,player1=0,player2=0,player=1;
int culoare1=0,culoare2=12,culoare3=15,culoare4=4,timenr,q=0,r,rl=0,rrl=0,rc=0,rrc=0,rd=0,rrd=0,rrandom1=0,random1=0,rrandom2,ww[21][21],redo=0,aa=0,contur,finall=0,page,jumatate_patrat;
int vs,mat_sec1[100][100],mat_sec2[100][100],mat_sec3[100][100],kk,kk2,kk3,st=0;
struct proprietati_cerc
{
    int marime;
    int culoare;
} cerc;

struct coordonata_x
{
    int centru;
    int t;
    int inc;
    int sf;
    int loc;
    int dim;
    int mouse1;
    int mouse2;
    int p1;
    int p2;
} x;
struct coordonata_y
{
    int centru;
    int t;
    int inc;
    int sf;
    int loc;
    int dim;
    int mouse1;
    int mouse2;
    int p1;
    int p2;
} y;
struct poz
{
    int l, c, pasi;
} C[32000], X;
struct poz3
{
    int l3, c3, pasi3;
} C3[32000], X3;
int l93, c93,ic3 = 0, sc3 = -1;
int P[180][180], n, m, px=2, py=1,px4=1,py4=2,px7=1,py7=2,sx, sy;
int l9, c9, k, ic = 0, sc = -1;
int dl[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void lee(int px2,int py2)
{

    for(px2; px2<matxy; px2=px2+2)
    {
        sc=-1;
        ic=0;

        sc++;
        C[sc].l = px2;
        C[sc].c = py2;
        C[sc].pasi = 1;
        mat_sec1[px2][py2] = 1;
        while (ic <= sc)     //mai am elemente in coada
        {
            X = C[ic];
            ic++;       //scot un element din coada
            for (k = 0; k < 4; k++)//incerc in cele 4 directii
            {
                l9 = X.l + dl[k];
                c9 = X.c + dc[k];
                if (mat_sec1[l9][c9] == 0) //pot merge aici
                {
                    mat_sec1[l9][c9] = X.pasi + 1;

                    sc++;
                    C[sc].l = l9;
                    C[sc].c = c9;
                    C[sc].pasi = X.pasi + 1;
                }
            }
        }
    }

}

void lee2(int px3,int py3)
{

//    for(px3; px3<matxy; px3=px3+2)
  //  {
    //    sc=-1;
      //  ic=0;

        //sc++;
       // C[sc].l = px3;
       // C[sc].c = py3;
       // C[sc].pasi = 1;
       // mat_sec2[px3][py3] = 1;
       // while (ic <= sc)     //mai am elemente in coada
        //{
          //  X = C[ic];
          //  ic++;       //scot un element din coada
           // for (k = 0; k < 4; k++)//incerc in cele 4 directii
            //{
             //   l9 = X.l + dl[k];
              //  c9 = X.c + dc[k];
               // if (mat_sec2[l9][c9] == 0) //pot merge aici
               // {
                //    mat_sec2[l9][c9] = X.pasi + 1;

                  //  sc++;
                   // C[sc].l = l9;
                   // C[sc].c = c9;
                   // C[sc].pasi = X.pasi + 1;
            //    }
          //  }
       // }
   // }

}
void lee3(int px5,int py5)
{

    for(px5; px5<matxy; px5=px5+2)
    {
        sc3=-1;
        ic3=0;

        sc3++;
        C3[sc3].l3 = px5;
        C3[sc3].c3 = py5;
        C3[sc3].pasi3 = 1;
        mat_sec3[px5][py5] = 1;
        while (ic3 <= sc3)     //mai am elemente in coada
        {
            X3 = C3[ic3];
            ic3++;       //scot un element din coada
            for (k = 0; k < 4; k++)//incerc in cele 4 directii
            {
                l93 = X3.l3 + dl[k];
                c93 = X3.c3 + dc[k];
                if (mat_sec3[l93][c93] == 0) //pot merge aici
                {
                    mat_sec3[l93][c93] = X3.pasi3 + 1;

                    sc3++;
                    C3[sc3].l3 = l93;
                    C3[sc3].c3 = c93;
                    C3[sc3].pasi3 = X3.pasi3 + 1;
                }
            }
        }
    }

}


int contor,spatiu=10;
int d=0,i,j;
int main()
{
    x.t=900,y.t=900;
    int q=4,dis=80;
    initwindow(x.t,y.t);
    while(finall==0)
    {
        while(startgame==0)
        {

//meniu-in.

            if(page==1)
            {

                setvisualpage(1);
                setactivepage(1);

                page=2;


            }
            if(page==0)
            {


                setactivepage(1);
                setvisualpage(0);


                page=1;

            }


            //butoane meniu


            int xlb=0,ylb=0;
            if(page==1)
            {
                while(xlb<1000 && ylb<1000)
                {
                    setfillstyle(SOLID_FILL,8);

                    setcolor(8);
                    bar(xlb,ylb,xlb+16*4,ylb+16*4);
                    setcolor(BLUE);
//setfillpattern();
                    setfillstyle(SOLID_FILL,BLUE);
                    bar(xlb,ylb,xlb+4,ylb+15*4);
                    bar(xlb+4,ylb,xlb+2*4,ylb+14*4);
                    bar(xlb+2*4,ylb,xlb+3*4,ylb+13*4);
                    bar(xlb+3*4,ylb,xlb+4*4,ylb+12*4);
                    bar(xlb+4*4,ylb,xlb+5*4,ylb+11*4);
                    bar(xlb+5*4,ylb,xlb+6*4,ylb+10*4);
                    bar(xlb+6*4,ylb,xlb+7*4,ylb+9*4);
                    bar(xlb+7*4,ylb,xlb+8*4,ylb+8*4);
                    bar(xlb+8*4,ylb,xlb+9*4,ylb+7*4);
                    bar(xlb+9*4,ylb,xlb+10*4,ylb+6*4);
                    bar(xlb+10*4,ylb,xlb+11*4,ylb+5*4);
                    bar(xlb+11*4,ylb,xlb+12*4,ylb+4*4);
                    bar(xlb+12*4,ylb,xlb+13*4,ylb+3*4);
                    bar(xlb+13*4,ylb,xlb+14*4,ylb+2*4);
                    bar(xlb+14*4,ylb,xlb+15*4,ylb+4);

                    setcolor(0);
                    setfillstyle(SOLID_FILL,0);

                    bar(xlb,ylb,xlb+4,ylb+4);
                    bar(xlb+4,ylb+4,xlb+2*4,ylb+2*4);
                    bar(xlb+2*4,ylb+2*4,xlb+3*4,ylb+3*4);
                    bar(xlb+3*4,ylb+3*4,xlb+4*4,ylb+4*4);
                    bar(xlb+4*4,ylb+4*4,xlb+12*4,ylb+12*4);
                    bar(xlb+12*4,ylb+12*4,xlb+13*4,ylb+13*4);
                    bar(xlb+13*4,ylb+13*4,xlb+14*4,ylb+14*4);
                    bar(xlb+14*4,ylb+14*4,xlb+15*4,ylb+15*4);
                    bar(xlb+15*4,ylb+15*4,xlb+16*4,ylb+16*4);
                    xlb=xlb+15*4;
                    if(xlb>900 && ylb<900)
                    {
                        xlb=0;
                        ylb=ylb+15*4;
                    }
                }
                setcolor(culoare2);
        settextstyle(6,0,9);
        outtextxy(x.t/q-dis-20,y.t/q-2*dis,"BRIDG-IT");

        settextstyle(6,0,5);
        outtextxy(x.t/q,y.t/q,"START GAME");
        outtextxy(x.t/q-20,y.t/q+dis,"INSTRUCTIONS");

        outtextxy(x.t/q+120,y.t/q+2*dis,"EXIT");

        rectangle(x.t/q,y.t/q,x.t/q+385,y.t/q+40);
        rectangle(x.t/q-20,y.t/q+dis,x.t/q+420,y.t/q+dis+40);

        rectangle(x.t/q+120,y.t/q+2*dis,x.t/q+260,y.t/q+2*dis+40);;

            }
            //verificare daca este un butun apasat cu mouse-ul(daca da schimba ecranul)

            bool click=false;

            if(ismouseclick(WM_LBUTTONDOWN))
            {
                clearmouseclick(WM_LBUTTONDOWN);

                x_x=mousex();         //coordonate mouse
                y_y=mousey();         //coordonate mouse


                //verifica daca click-ul este in vreun chenar al butoanelor
                if (x_x>=x.t/q && x_x<=x.t/q+385 && y_y>=y.t/q && y_y<=y.t/q+40)
                    startgame=4;
                if (x_x>=x.t/q && x_x<=x.t/q+440 && y_y>=y.t/q+dis && y_y<=y.t/q+dis+40)
                {
                    startgame=2;
                }
                if (x_x>=x.t/q && x_x<=x.t/q+290 && y_y>=y.t/q+2*dis && y_y<=y.t/q+2*dis+40)
                    {
                    closegraph();
                    return 0;
                }


                click=true;
            }
            click=false;
        }


if(startgame==2)
    {
 x.t=900,y.t=900;
        initwindow(x.t,y.t);
        int t;
        if(t==0)
         {
        setbkcolor(DARKGRAY);
        setactivepage(1);
        setvisualpage(1);



t=1;
         }
            cleardevice();
            setfillstyle(SOLID_FILL,DARKGRAY);
        floodfill(200,200,DARKGRAY);
setbkcolor(DARKGRAY);setcolor(culoare2);
            settextstyle(6,0,8);
            outtextxy(35,50,"INSTRUCTIONS");
            settextstyle(6,0,3);
            outtextxy(75,200,"  Regulile pentru a juca Bridg-It sunt urmatoarele:");
            outtextxy(75,240,"    jucatorii leaga pe rand doua puncte adiacente");
            outtextxy(75,280,"         de propria lor culoare cu un pod.");
            outtextxy(75,320,"    Punctele adiacente sunt considerate puncte");
            outtextxy(75,360,"direct deasupra, dedesubt, la dreapta sau la stanga");
            outtextxy(75,400," altui punct cu aceeasi culoare.Podul nou format nu");
            outtextxy(75,440,"  poate traversa un pod deja jucat si oricine le");
            outtextxy(75,480," leaga marginile opuse ale tablei primul castiga.");
        bool click=false;
        getch();

    }
        while(startgame==3)
        {





            cleardevice();

        }
 settextstyle(3,0,6);

        while(startgame==4)
        {
            if(st==0)
            {
          setvisualpage(9);
          setactivepage(10);
            cleardevice();
            st++;
            }


              outtextxy(200,300,"Player vs Player");
                            outtextxy(200,400,"Player vs Computer");

              // rectangle(200,300,580,350);

                //rectangle(200,400,655,450);
                bool click=false;

                if(ismouseclick(WM_LBUTTONDOWN))
            {
                clearmouseclick(WM_LBUTTONDOWN);

                x_x=mousex();         //coordonate mouse
                y_y=mousey();         //coordonate mouse


                //verifica daca click-ul este in vreun chenar al butoanelor
                 if (x_x>=200 && x_x<=580 && y_y>=300 && y_y<=350)
              {
                  startgame=1;
                  vs=1;
              }
               if (x_x>=200 && x_x<=650 && y_y>=400 && y_y<=450)
              {
                  startgame=1;
                  vs=2;
              }

                click=true;
            }
            click=false;
        }



//meniu-fin.




        if(startgame==1)
        {
            x.t=900,y.t=900;      //dimensiuni ecran(dimensiunile totale)
            cerc.marime=15;       //raza cercului
            int t;

            //pagina ecranului
            if(t==0)
        {
            setactivepage(3);
            setvisualpage(3);

            cleardevice();
            setbkcolor(DARKGRAY);
            t=1;
        }
        cleardevice();
            setfillstyle(SOLID_FILL,DARKGRAY);
        floodfill(200,200,DARKGRAY);
setbkcolor(DARKGRAY);setcolor(culoare2);
            settextstyle(6,0,9);
            outtextxy(125,50,"BRIDG-IT");
        bool click=false;

//   cin>>x.t>>y.t;
            int i,j,k=0,l=0;
            setcolor(culoare1);
            y.centru=y.t/2;
            x.centru=x.t/2;
            nr_y_ex=nr_x_ex+1;



            matxy=nr_x_ex+nr_y_ex;

            for(i=0; i<=matxy+1; i++)
                for(j=0; j<=matxy+1; j++)
                    w[i][j]=-1;

            for(i=1; i<=matxy; i++)
                for(j=1; j<=matxy; j++)
                    w[i][j]=0;



            //
            //while(c==0)
            //  {
            //   cout<<cerc.marime<<" ";
            //  if(matxy*(cerc.marime*2+spatiu)<x.t-x.limita && matxy*(cerc.marime*2+spatiu)<y.t-y.limita)
            //      c=1;
            //  else
            //  {

            //     cerc.marime--;
            //     spatiu--;
            //  }
            //  }
            jumatate_patrat=cerc.marime+spatiu;
            y.inc=y.centru-(matxy*(jumatate_patrat));
            y.sf=y.centru+(matxy*(jumatate_patrat))-2*jumatate_patrat;
            x.inc=x.centru-(matxy*(jumatate_patrat));
            x.sf=x.centru+(matxy*(jumatate_patrat))-2*jumatate_patrat;
            //centrul ultimului cerc(coordonata x)
            //   cout<<x.inc<<" "<<x.sf;
//cout<<x.t<<" "<<y.t<<'\n';
//cout<<x.inc<<" "<<x.sf<<" "<<y.inc<<" "<<y.sf;


            for(j=y.inc; j<=y.sf; j=j+(2*jumatate_patrat))
            {
                l++;         //contor cercuri pe verticala
                k=0;

                for(i=x.inc; i<=x.sf; i=i+(2*jumatate_patrat))
                {


                    k++;        //contor cercuri pe orizontala
                    setcolor(culoare1);
                    if(k%2==0 && l%2==1)      //daca este un cerc pe o pozitie cu i-ul par si j-ul impar adauga un cerc albastru si conturul verde
                    {

                        setfillstyle(SOLID_FILL,culoare1);
                        fillellipse(i,j,cerc.marime,cerc.marime);
                        setcolor(culoare3);
                        setlinestyle(1, 0, 5);
                        rectangle(i-jumatate_patrat,j-jumatate_patrat,i+jumatate_patrat,j+jumatate_patrat);
                        w[k][l]=1;         //cercurile de culoare albastru au valoarea 1 in matrice
                    }
                    if(k%2==1 && l%2==1)
                    {
                        setcolor(culoare3);
                        setlinestyle(1, 0, 5);
                        rectangle(i-jumatate_patrat,j-jumatate_patrat,i+jumatate_patrat,j+jumatate_patrat);
                    }
                    if(k%2==0 && l%2==0)
                    {
                        setcolor(culoare3);
                        setlinestyle(1, 0, 5);
                        rectangle(i-jumatate_patrat,j-jumatate_patrat,i+jumatate_patrat,j+jumatate_patrat);
                    }
                    setcolor(culoare2);

                    if(k%2==1 && l%2==0)
                    {
                        setfillstyle(SOLID_FILL,culoare2);
                        fillellipse(i,j,cerc.marime,cerc.marime);
                        setcolor(culoare3);
                        setlinestyle(1, 0, 5);
                        rectangle(i-jumatate_patrat,j-jumatate_patrat,i+jumatate_patrat,j+jumatate_patrat);

                        w[k][l]=2;


                    }
                }
            }

            //     setcolor(culoare3);
            //    setlinestyle(1, 0, 5);





            for(i=0; i<=matxy+1; i++)
                for(j=0; j<=matxy+1; j++)
                {
                    mat_sec1[i][j]=-1;
                }
            for(i=0; i<=matxy+1; i++)
                for(j=0; j<=matxy+1; j++)
                {
                    mat_sec2[i][j]=-1;
                }
             for(i=0; i<=matxy+1; i++)
                for(j=0; j<=matxy+1; j++)
                {
                    mat_sec3[i][j]=-1;
                }




            while(startgame==1)
            {

                for(i=0; i<=matxy+1; i++)
                    for(j=0; j<=matxy+1; j++)
                        if(mat_sec1[j][i]>0)
                            mat_sec1[j][i]=0;

                    for(i=0; i<=matxy+1; i++)
                    for(j=0; j<=matxy+1; j++)
                        if(mat_sec2[j][i]>0)
                            mat_sec2[j][i]=0;

                      for(i=0; i<=matxy+1; i++)
                    for(j=0; j<=matxy+1; j++)
                        if(mat_sec3[j][i]>0)
                            mat_sec3[j][i]=0;

lee(px,py);
lee2(px4,py4);
                 lee3(px7,py7);

                for(kk=2; kk<matxy; kk=kk+2)
                    if(mat_sec1[kk][matxy]!=0 && mat_sec1[kk][matxy]!=-1)
                        return 0;
                kk=2;
                for(kk2=2; kk2<matxy; kk2=kk2+2)
                    if(mat_sec2[matxy][kk2]!=0 && mat_sec2[matxy][kk2]!=-1)
                        return 0;
                kk2=2;

                for(kk3=2; kk3<matxy; kk3=kk3+2)
                    if(mat_sec3[matxy][kk3]!=0 && mat_sec3[matxy][kk3]!=-1)
                        return 0;
                kk3=2;


                if(player==2)
                {
                    //   x_x2=mousex();
                    //   y_y2=mousey();
                    if(vs==2)
                        player2=1;




                }

                if(player2==1)
                {
                    setfillstyle(SOLID_FILL,culoare2);

                    if(timenr==0)
                        srand((int)time(0));
                    timenr=1;
                    if(rl++ < 10000)
                    {
                        rrl = (rand() % matxy) + 1;

                        //rr++;

                        // cout<<rrl<<" ";

                    }
                    if(rc++ < 10000)
                    {
                        rrc = (rand() % matxy) + 1;

                        //rr++;
                        // cout<<rrl<<" ";

                    }

lee(px,py);
lee2(px4,py4);

                     lee3(px7,py7);







                    //   cout<<aa<<'\n';

                    if(w[rrl][rrc]==0 && rrc!=1 && rrc!=matxy)
                    {
                        aa++;
                        w[rrl][rrc]=2;
                        mat_sec2[rrl][rrc]=0;
                        if(w[rrl-1][rrc]==2)
                            mat_sec2[rrl-1][rrc]=0;
                        if(w[rrl][rrc-1]==2)
                            mat_sec2[rrl][rrc-1]=0;
                        if(w[rrl][rrc+1]==2)
                            mat_sec2[rrl][rrc+1]=0;
                        if(w[rrl+1][rrc]==2)
                            mat_sec2[rrl+1][rrc]=0;

                        setlinestyle(0, 0, 1);

                        setcolor(culoare2);

                        rectangle((rrl-1)*x.dim+x.inc-spatiu, (rrc-1)*y.dim+y.inc-spatiu, (rrl-1)*x.dim+x.inc+spatiu-cerc.marime+cerc.marime, (rrc-1)*y.dim+y.inc+spatiu-cerc.marime+cerc.marime);
                        floodfill((rrl-1)*x.dim+x.inc-spatiu+1, (rrc-1)*y.dim+y.inc-spatiu+1, culoare2);
                    }

                    if(aa!=0)
                    {
                        player=1;
                        aa=0;
                        player2=0;

                    }
                }

                if(ismouseclick(WM_LBUTTONDOWN))
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    if(player==1)
                    {
                        x_x1=mousex();
                        y_y1=mousey();
                        player1=1;





                    }
                    if(player==2)
                    {
                        x_x2=mousex();
                        y_y2=mousey();
                        player2=3;

                    }




                    if(player1==1)
                    {

                        setfillstyle(SOLID_FILL,culoare1);

                        if (x_x1>=x.inc-jumatate_patrat && x_x1<=x.sf+jumatate_patrat && y_y1>=y.inc-jumatate_patrat && y_y1<=y.sf+jumatate_patrat)
                        {
                            // cout<<"yes"<<'\n';

                            x.loc=x.sf+jumatate_patrat-(x.inc-jumatate_patrat);
                            y.loc=y.sf+jumatate_patrat-(y.inc-jumatate_patrat);


                            //     cout<<x.inc-cerc.marime-spatiu<<" "<<x.sf-cerc.marime-spatiu <<'\n';
                            //   cout<<y.inc-cerc.marime-spatiu<<" "<<y.sf-cerc.marime-spatiu <<'\n';

                            x.dim=x.loc/matxy;
                            y.dim=y.loc/matxy;

                            x.mouse1=((x_x1-(x.inc-jumatate_patrat))/x.dim)+1;
                            y.mouse1=((y_y1-(y.inc-jumatate_patrat))/y.dim)+1;



















                            if(w[x.mouse1][y.mouse1]==1 && patrat_p1==1)
                            {
                                if( (x.mouse1==x.p1 && y.mouse1-y.p1<=2 && y.mouse1-y.p1>=-2))
                                {
                                    if(y.mouse1>y.p1 && w[x.mouse1][y.mouse1-1]==0)
                                    {
                                        setlinestyle(0, 0, 1);

                                        setcolor(culoare1);

                                        rectangle((x.mouse1-1)*x.dim+x.inc-spatiu, (y.mouse1-2)*y.dim+y.inc-spatiu, (x.mouse1-1)*x.dim+x.inc+spatiu-cerc.marime+cerc.marime, (y.mouse1-2)*y.dim+y.inc+spatiu-cerc.marime+cerc.marime);
                                        floodfill((x.mouse1-1)*x.dim+x.inc-spatiu+1, (y.mouse1-2)*y.dim+y.inc-spatiu+1, culoare1);


                                        w[x.mouse1][y.mouse1-1]=1;
                                        fout<<x.mouse1<<" "<<y.mouse1<<'\n';

                                        mat_sec1[x.mouse1][y.mouse1-1]=0;
                                        mat_sec1[x.mouse1][y.mouse1]=0;
                                        mat_sec1[x.p1][y.p1]=0;
                                        patrat_p1=2;



                                    }
                                    if(y.p1>y.mouse1 && w[x.mouse1][y.p1-1]==0)
                                    {
                                        setlinestyle(0, 0, 1);

                                        setcolor(culoare1);

                                        rectangle((x.p1-1)*x.dim+x.inc-spatiu, (y.p1-2)*y.dim+y.inc-spatiu, (x.p1-1)*x.dim+x.inc+spatiu-cerc.marime+cerc.marime, (y.p1-2)*y.dim+y.inc+spatiu-cerc.marime+cerc.marime);
                                        floodfill((x.p1-1)*x.dim+x.inc-spatiu+1, (y.p1-2)*y.dim+y.inc-spatiu+1, culoare1);


                                        w[x.mouse1][y.p1-1]=1;
                                        fout<<x.mouse1<<" "<<y.p1-1<<'\n';
                                        mat_sec1[x.mouse1][y.p1-1]=0;
                                        mat_sec1[x.mouse1][y.mouse1]=0;
                                        mat_sec1[x.p1][y.p1]=0;
                                        patrat_p1=2;
                                    }
                                }

                                if(y.mouse1==y.p1 && x.mouse1-x.p1<=2 && x.mouse1-x.p1>=-2)
                                {

                                    if(x.mouse1>x.p1 && w[x.mouse1-1][y.mouse1]==0)
                                    {
                                        setlinestyle(0, 0, 1);

                                        setcolor(culoare1);


                                        rectangle((x.mouse1-2)*x.dim+x.inc-spatiu, (y.mouse1-1)*y.dim+y.inc-spatiu, (x.mouse1-2)*x.dim+x.inc+spatiu-cerc.marime+cerc.marime, (y.mouse1-1)*y.dim+y.inc+spatiu-cerc.marime+cerc.marime);
                                        floodfill((x.mouse1-2)*x.dim+x.inc-spatiu+1, (y.mouse1-1)*y.dim+y.inc-spatiu+1, culoare1);


                                        w[x.mouse1-1][y.mouse1]=1;
                                        fout<<x.mouse1-1<<" "<<y.mouse1<<'\n';
                                        mat_sec1[x.mouse1-1][y.mouse1]=0;
                                        mat_sec1[x.mouse1][y.mouse1]=0;
                                        mat_sec1[x.p1][y.p1]=0;


                                        patrat_p1=2;



                                    }
                                    if(x.p1>x.mouse1 && w[x.p1-1][y.mouse1]==0)
                                    {

                                        setlinestyle(0, 0, 1);

                                        setcolor(culoare1);


                                        rectangle((x.p1-2)*x.dim+x.inc-spatiu, (y.p1-1)*y.dim+y.inc-spatiu, (x.p1-2)*x.dim+x.inc+spatiu-cerc.marime+cerc.marime, (y.p1-1)*y.dim+y.inc+spatiu-cerc.marime+cerc.marime);
                                        floodfill((x.p1-2)*x.dim+x.inc-spatiu+1, (y.p1-1)*y.dim+y.inc-spatiu+1, culoare1);


                                        w[x.p1-1][y.mouse1]=1;
                                        fout<<x.p1-1<<" "<<y.mouse1<<'\n';

                                        mat_sec1[x.p1-1][y.mouse1]=0;
                                        mat_sec1[x.mouse1][y.mouse1]=0;
                                        mat_sec1[x.p1][y.p1]=0;

                                        patrat_p1=2;
                                    }

                                }

                                if(patrat_p1==1)
                                    patrat_p1=0;
                            }
                            if(w[x.mouse1][y.mouse1]==1 && patrat_p1==0)
                            {
                                patrat_p1=1;
                                x.p1=x.mouse1;
                                y.p1=y.mouse1;

                            }
                            if(patrat_p1==2)
                            {
                                patrat_p1=0;
                                patrat_p2=0;


                                player=2;
                                player1=0;
                                aa=0;


                            }
                            if(player==1)
                            {
                                x_x2=mousex();
                                y_y2=mousey();
                                player2=3;



                            }

                            // cout<<patrat_p1<<"\n";


                        //       cout<<player<<'\n';

//cout<<player1<<" "<<player2<<"\n";




                        }
                    }
                    cout<<player<<" "<<player2<<'\n';


if(player2==3)
                {

                     setfillstyle(SOLID_FILL,culoare2);

                    if (x_x2>=x.inc-jumatate_patrat && x_x2<=x.sf+jumatate_patrat && y_y2>=y.inc-jumatate_patrat && y_y2<=y.sf+jumatate_patrat)
                    {
                        // cout<<"yes"<<'\n';

                        x.loc=x.sf+jumatate_patrat-(x.inc-jumatate_patrat);                   //dimensiune contur tabla
                        y.loc=y.sf+jumatate_patrat-(y.inc-jumatate_patrat);


                        //     cout<<x.inc-cerc.marime-spatiu<<" "<<x.sf-cerc.marime-spatiu <<'\n';
                        //   cout<<y.inc-cerc.marime-spatiu<<" "<<y.sf-cerc.marime-spatiu <<'\n';

                        x.dim=x.loc/matxy;                       //dimensiunea unui singur patrat
                        y.dim=y.loc/matxy;

                        x.mouse2=((x_x2-(x.inc-jumatate_patrat))/x.dim)+1;       //matrice numar linie
                        y.mouse2=((y_y2-(y.inc-jumatate_patrat))/y.dim)+1;         //matrice numar coloana



















                        if(w[x.mouse2][y.mouse2]==2 && patrat_p2==1)
                        {
                            if( (x.mouse2==x.p2 && y.mouse2-y.p2<=2 && y.mouse2-y.p2>=-2))
                            {
                                if(y.mouse2>y.p2 && w[x.mouse2][y.mouse2-1]==0)
                                {
                                    setlinestyle(0, 0, 1);

                                    setcolor(culoare2);

                                    rectangle((x.mouse2-1)*x.dim+x.inc-spatiu, (y.mouse2-2)*y.dim+y.inc-spatiu, (x.mouse2-1)*x.dim+x.inc+spatiu-cerc.marime+cerc.marime, (y.mouse2-2)*y.dim+y.inc+spatiu-cerc.marime+cerc.marime);
                                    floodfill((x.mouse2-1)*x.dim+x.inc-spatiu+1, (y.mouse2-2)*y.dim+y.inc-spatiu+1, culoare2);


                                    w[x.mouse2][y.mouse2-1]=2;
                                fout<<x.mouse2<<" "<<y.mouse2<<'\n';

                                     mat_sec3[x.mouse2][y.mouse2-1]=0;
                                        mat_sec3[x.mouse2][y.mouse2]=0;
                                        mat_sec3[x.p2][y.p2]=0;
                                    patrat_p2=2;



                                }
                                if(y.p2>y.mouse2 && w[x.mouse2][y.p2-1]==0)
                                {
                                    setlinestyle(0, 0, 1);

                                    setcolor(culoare2);

                                    rectangle((x.p2-1)*x.dim+x.inc-spatiu, (y.p2-2)*y.dim+y.inc-spatiu, (x.p2-1)*x.dim+x.inc+spatiu-cerc.marime+cerc.marime, (y.p2-2)*y.dim+y.inc+spatiu-cerc.marime+cerc.marime);
                                    floodfill((x.p2-1)*x.dim+x.inc-spatiu+1, (y.p2-2)*y.dim+y.inc-spatiu+1, culoare2);


                                    w[x.mouse2][y.p2-1]=2;
                                    fout<<x.mouse2<<" "<<y.p2-1<<'\n';
                                     mat_sec3[x.mouse2][y.p2-1]=0;
                                        mat_sec3[x.mouse2][y.mouse2]=0;
                                        mat_sec3[x.p2][y.p2]=0;
                                    patrat_p2=2;
                                }
                            }

                            if(y.mouse2==y.p2 && x.mouse2-x.p2<=2 && x.mouse2-x.p2>=-2)
                            {

                                if(x.mouse2>x.p2 && w[x.mouse2-1][y.mouse2]==0)
                                {
                                    setlinestyle(0, 0, 1);

                                    setcolor(culoare2);


                                    rectangle((x.mouse2-2)*x.dim+x.inc-spatiu, (y.mouse2-1)*y.dim+y.inc-spatiu, (x.mouse2-2)*x.dim+x.inc+spatiu-cerc.marime+cerc.marime, (y.mouse2-1)*y.dim+y.inc+spatiu-cerc.marime+cerc.marime);
                                    floodfill((x.mouse2-2)*x.dim+x.inc-spatiu+1, (y.mouse2-1)*y.dim+y.inc-spatiu+1, culoare2);


                                    w[x.mouse2-1][y.mouse2]=2;
                                    fout<<x.mouse2-1<<" "<<y.mouse2<<'\n';

                                   mat_sec3[x.mouse2-1][y.mouse2]=0;
                                        mat_sec3[x.mouse2][y.mouse2]=0;
                                        mat_sec3[x.p2][y.p2]=0;

                                    patrat_p2=2;



                                }
                                if(x.p2>x.mouse2 && w[x.p2-1][y.mouse2]==0)
                                {

                                    setlinestyle(0, 0, 1);

                                    setcolor(culoare2);


                                    rectangle((x.p2-2)*x.dim+x.inc-spatiu, (y.p2-1)*y.dim+y.inc-spatiu, (x.p2-2)*x.dim+x.inc+spatiu-cerc.marime+cerc.marime, (y.p2-1)*y.dim+y.inc+spatiu-cerc.marime+cerc.marime);
                                    floodfill((x.p2-2)*x.dim+x.inc-spatiu+1, (y.p2-1)*y.dim+y.inc-spatiu+1, culoare2);


                                    w[x.p2-1][y.mouse2]=2;
                                    fout<<x.p2-1<<" "<<y.mouse2<<'\n';

                                   mat_sec3[x.p2-1][y.mouse2]=0;
                                        mat_sec3[x.mouse2][y.mouse2]=0;
                                        mat_sec3[x.p2][y.p2]=0;

                                    patrat_p2=2;
                                }

                            }
                             if(patrat_p2==1)
                        {
                            patrat_p2=0;
                        }
                        }
                 // cout<<patrat_p1<<" "<<patrat_p2<<"\n";


                        if(w[x.mouse2][y.mouse2]==2 && patrat_p2==0)
                        {
                            patrat_p2=1;
                            x.p2=x.mouse2;
                            y.p2=y.mouse2;

                        }
                        if(patrat_p2==2)
                        {
                            patrat_p2=0;
                            patrat_p1=0;

                            player=1;
                            player2=0;



                        }


                        //  cout<<patrat_p2<<"\n";
                    }



                }
                       cout<<x.mouse1<<" "<<y.mouse1<<" "<<x.p1<<" "<<y.p1<<" "<<patrat_p2<<" "<<x.mouse2<<" "<<y.mouse2<<" "<<x.p2<<" "<<y.p2<<"\n";

                    //  fout<<nrnod<<" ";
//system("CLS");
                    //   cout<<rrl<<" "<<rrc<<"\n";














                    for(i=0; i<=matxy+1; i++)
                    {
                        for(j=0; j<=matxy+1; j++)
                            cout<<mat_sec3[j][i]<<" ";
                        cout<<"\n";
                    }





                    //  lee();
                    //   cout<<x.mouse1<<" "<<y.mouse1 <<" "<<rrl<<" "<<rrc<<" "<<player2;




                    //}
//fout<<"\n";





                    click=true;
                }
                click=false;

                int st,dr,sus,jos;
                int rezultat,r[100][100],directie;
                i=1;
                j=0;



            }




        }
    }

//cout<<x.inc<<" "<<y.inc;

    closegraph();

    return 0;
}
