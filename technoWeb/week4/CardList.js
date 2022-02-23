import  React  from 'react';
import Card from './Card';

class CardList extends React.Component {

    constructor(props) {
        super(props);
        this.state = {
            Cartes : [
                {id: 1, Card: "toto", feedback : 'hidden'}, 
                {id: 2, Card: "titi", feedback : 'hidden'},
            ],
        }
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

