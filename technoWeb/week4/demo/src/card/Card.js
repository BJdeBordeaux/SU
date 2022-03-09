import  {Component}  from 'react';

class Card extends Component {
    constructor(props) {
        super(props);
        this.state = {
            affichage: props.affichage,
        }

        this.handleCardClick = this.handleCardClick.bind(this);
    }

    handleCardClick(){
        if(this.state.affichage === 'hidden'){
            this.setState({affichage: 'visible'});
        }
    }

    render() {
        return (
            <div className="cards" onClick={() => this.handleCardClick()}>{this.state.affichage==='visible'?this.props.symbol:'_'}</div>
            
        );
    }
}

export default Card;
