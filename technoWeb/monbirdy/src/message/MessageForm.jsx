import {  Component } from "react";
import { Card, CardBody, Form, FormGroup, Input, Label } from "reactstrap";

class MessageForm extends Component{
    constructor(props){
        super(props);
    }

    render(){
        return(
            <Form>
                <FormGroup><Label>Message</Label><Input type="textarea" placeholder="enter your comment"></Input></FormGroup>
            </Form>
        );
    }
}

export default MessageForm;