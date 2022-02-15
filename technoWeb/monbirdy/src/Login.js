import React from "react";
import {
    Label,
    Input,
    Button,
    Form,
    FormGroup
} from "reactstrap";
class Login extends React.Component{
    constructor(props) {
        super(props);
    }

    render() {
        return(
            <Form >
                <FormGroup row className="col-md-6"><Label>Username</Label><Input type='text' name='username' placeholder="username"></Input></FormGroup>
                <FormGroup row className="col-md-6"><Label>Password</Label><Input type='password' name='password' placeholder="password"></Input></FormGroup>
                <Button onClick={this.props.getConnected}>Log in</Button>
            </Form>
        );
    }
}

export default Login;