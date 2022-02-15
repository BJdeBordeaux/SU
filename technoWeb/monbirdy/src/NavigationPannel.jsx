import React from "react";
import Logout from "./Logout";
import Login from "./Login";


class NavigationPannel extends React.Component{
    constructor(props) {
        super(props);
    }

    render() {
        return(
          <nav>{this.props.isConnected === true
              ?<Logout getLogout={this.props.logout}></Logout>
              :<Login getConnected={this.props.login}></Login>}
          </nav>
        

        );
    }
}

export default NavigationPannel;