import React from 'react'
import {
    Card,
    CardBody,
    Label,
    Input,
    Button,
    Form,
    FormGroup
} from "reactstrap";

class Signin extends React.Component{
    
    render(){
        return (
            <Form>
                <FormGroup><Label>username</Label><Input type='text' name='username' placeholder='username'></Input></FormGroup>
                <FormGroup><Label>email</Label><Input type='email' name='email' placeholder='email'></Input></FormGroup>
                <FormGroup><Label>password</Label><Input type='password' name='password' placeholder='password'></Input></FormGroup>
                <FormGroup><Label>alias</Label><Input type='text' name='alias' placeholder='alias'></Input></FormGroup>
                <Button type='submit'>Submit</Button>
            </Form>
        );
    }
}

export default Signin;