import React from "react";
import { } from "reactstrap";


export default class TestedLetters extends React.Component{
    
    constructor(props) {
        super(props);
        this.state = {
            testedLetters: []
        }
        
    }

    constructWordString = ()=>{
        let seperator = "_";

        let wordString = Array(this.state.wordLength).map((_, index)=>seperator);
        return wordString;
    }

    render(){
        let wordPendu = this.state.testedLetters.sort().join(" ");
        return(
            <p color="primary">{wordPendu}</p>
        );
    }
}