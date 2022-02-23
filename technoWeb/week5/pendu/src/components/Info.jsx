import React from "react";
import { } from "reactstrap";


export default class info extends React.Component{
    
    constructor(props) {
        super(props);
        this.state = {
            info: ''
        }
        
    }

    constructWordString = ()=>{
        let seperator = "_";

        let wordString = Array(this.state.wordLength).map((_, index)=>seperator);
        return wordString;
    }

    render(){
        let letterString = this.state.testedLetters.sort().join(" ");
        return(
            <p>{letterString}</p>
        );
    }
}