import React from "react";

class Logout extends React.Component{
    constructor(props) {
        super(props);
    }

    render() {
        return(
            <button onClick={this.props.getLogout}>Log out</button>
        );
    }
}

export default Logout;