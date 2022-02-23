import React from "react";
import { Badge } from "reactstrap";


export default class Score extends React.Component{
    constructor(props) {
        super(props);
        this.state = {
            score : 0,
        }
    }

    render(){
        return(
            <Badge color="info">Score: {this.state.score}</Badge>
        );
    }
}