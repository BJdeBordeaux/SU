import {Component} from 'react';
import axios from 'axios';
import Card from './Card';
import CardList from './CardList';
import FormAddCard from './FormAddCard'

export default class PageCard extends Component{
    constructor(props){
        super(props);
        this.state = {
            cards:[

            ]
        }
        this.addCard = this.addCard.bind(this);
        this.send = this.send.bind(this);

        this.api = axios.create({
            baseURL: "http://localhost:8080/monbirdy",
            timeout: 1000,
            headers:{
                'custom head' : "header",
                'Access-Control-Allow-Origin': '*',
                'Content-type':'application/json:charset=UTF-8',
            }
        });
    }




    componentDidMount(){
        
    }


    send(data){
        this.api.post("/login", {login: data.login, password: data.password})
        .then((response) => {
            setStatus("");
            login(response.data["session_key"]);
        }).catch((err) => {
            setStatus("error");
            console.error(err);
            setErrorText(err.data["description"])
        });
    }



    addCard(Card){
        this.state.setState((prev_state) => {
            prev_state.cards = prev_state.cards.concat(Card);
        })
    }

    render(){
        return(
            <div>
                <CardList/>
                <FormAddCard addCard={this.addCard}/>
            </div>
        );
    }
}