class PageCard extends React.Component{
    constructor(props){
        super(props);
        this.state = {
            cards:[

            ]
        }
    }

    addCard(Card){
        this.state.setState((prev_state) => {
            prev_state.cards = prev_state.cards.concat(Card);
        })
    }

    render(){
        return(
            <FormAddCard addCard={this.addCard()}/>
        );
    }
}