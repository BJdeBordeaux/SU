import logo from './logo.svg';
import './App.css';
import { Container, Row } from 'reactstrap';
import Word from './components/Word';
import BootstrapNavbar from './examples/BootstrapNavbar';
import MyNavbar from './examples/MyNavbar';

function App() {
  return (
    // <Container className='bg-light border' fluid>
    //   <Row><Word/></Row>
    //   <Row></Row>
    //   <Row></Row>
    //   <Row>Hello</Row>
    // </Container>
    <Container>
      <BootstrapNavbar/>
      <MyNavbar/>
    </Container>
  );
}

export default App;
