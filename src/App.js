import Pages from "./pages/Pages";
import Category from "./components/Category";
import {BrowserRouter,Link} from 'react-router-dom';
import Search from "./components/Search";
import styled from "styled-components";
import {SiCodechef} from "react-icons/si";

function App() {
  return (
    <div className="App">
      <BrowserRouter>
        <Nav>
          <SiCodechef size={70} />
          <Logo to={'/'}>Home</Logo>
        </Nav>
        <Search />
        <Category />
        <Pages />
      </BrowserRouter>
    </div>
  );
}

const Logo=styled(Link)`
 text-decoration:none;
 font-size:2.5rem;
 font-weight: 400;
 font-family: 'Lobster Two, cursive;
 height:2;
 width:2;
`;
const Nav=styled.div`
  padding: 4rem 0rem;
  display: flex;
  justify-content: flex-start;
  align-items:center;
  svg{
    fonst-size:2rem;
  }
`;


export default App;
