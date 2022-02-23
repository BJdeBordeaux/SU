import React from "react";
import { Badge } from "reactstrap";


export default class Life extends React.Component{
    constructor(props) {
        super(props);
        this.state = {
            life: 0,
        }
    }

    render(){
        return(
            <Badge color="success">Life: {this.state.life}</Badge>
        );
    }
}