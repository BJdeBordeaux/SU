import  React  from 'react';
import axios from "axios";
import Card from './Card';

export default class CardList extends React.Component {

    constructor(props) {
        super(props);
        this.state = {
            Cartes : [
                {id: 1, Card: "toto", feedback : 'hidden'}, 
                {id: 2, Card: "titi", feedback : 'hidden'},
            ],
        }
    }

    componentDidMount(){
        const api = axios.create({
            baseURL : "http://localhost:8080/",
            timeOut : 1000,
            header: {"customheader": "myheader"},
        });
        api.get("CardList") // asynchrone
        .then((response=>{
            const posts = response.data.slice(0, 4);
            const updatePost = posts.map(post=>{
                return {...post, coulou:"noir"};
            })
        }));
    }


    render() {
        
        return (
            <div className="card">{this.state.Cartes.map((card, index) => {
                return <Card symbol={card.Card} affichage={card.feedback}/>
            })}
            </div>
        )
    }
}

