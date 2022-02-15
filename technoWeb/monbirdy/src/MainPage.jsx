import React from 'react';
import { Container } from 'reactstrap';
import NavigationPannel from './NavigationPannel';
import Signin from './Signin';

class MainPage extends React.Component{
    constructor(props){
        super(props);
        this.state = {
            currentPage: 'login',
            isConnected: false,
        };
        
        // this.setLogout = this.setLogout.bind(this);
    }

    getConnected = ()=>{
        this.setState({
            currentPage: 'tweetWall',
            isConnected: true,
        })
    }

    setLogout = () => {
        if(this.state.isConnected === true){
            this.setState({
                currentPage: 'login',
                isConnected: false,
            });
        }
            
    }

    render(){
        return (
            <Container>
                <NavigationPannel login={this.getConnected} logout={this.setLogout} isConnected={this.state.isConnected}/>
                
                <div className='col-md-6 col-md-push-3'>{(this.state.currentPage === 'login')?<Signin/>:<></>}</div>
            </Container>
        )
    }
}

export default MainPage;