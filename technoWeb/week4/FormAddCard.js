class FormAddCard extends React.Component{
    constructor(props){
        super(props);
    }

    send(event){
        var data_to_send={
            Card: this.ref.symbol.value,
            feedback: this.props.display.value,
        }
        this.props.addCard(data_to_send)
    }

    render(){
        return (
            <div>
                <label>symbol</label><input name="symbol"></input>
                <label>visibility</label><select>
                    <option value='visible'>visible</option>
                    <option value='hidden'>hidden</option>
                </select>
                <input type='submit' value='submit' onClick={(Event)=>this.send()}>Create Card</input>
            </div>
        );
    }
}