import React from "react";
import { Button } from "reactstrap";


export default class Word extends React.Component{
    
    constructor(props) {
        super(props);
        this.state = {
            wordLength: this.props.word.length,
            wordString: this.constructWordString(),

        }
        
    }

    constructWordString = ()=>{
        let seperator = "_";

        let wordString = Array(this.state.wordLength).map((_, index)=>seperator);
        return wordString;
    }

    render(){
        let wordPendu = this.state.wordString.join(" ");
        return(
            <p color="primary">{wordPendu}</p>
        );
    }
}