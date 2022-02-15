import {  Component } from "react";
import { Container } from "reactstrap";
import MessageForm from "./MessageForm";
import MessageList from "./MessageList";

class MessageBox extends Component{
    constructor(props){
        super(props);
    }

    render(){
        return(
            <Container>
                <MessageList></MessageList>
                <MessageForm></MessageForm>
            </Container>
        );
    }
}

export default MessageBox;