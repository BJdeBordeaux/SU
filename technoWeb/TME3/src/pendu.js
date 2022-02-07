const { rejects } = require('assert')
const { resolve } = require('path')

class Pendu{
    constructor(mot_a_trouver, max_errors){
        this.mot_a_trouver = mot_a_trouver
        this.max_errors = max_errors || 5
        this.errors = 0
        this.foundcount = 0
        this.mot = []
        for (let index = 0; index < this.mot_a_trouver.length; index++) {
            this.mot[index] = "_";
        }
    }

    show(){
        console.log(`Erreur : ${this.errors}`);
        console.log(this.mot.join(" "))
        console.log()        
    }

    keypressed(c){
        
        let index = 0;
        for (; index < this.mot.length; index++) {
            if(this.mot[index].localeCompare("_") != 0){
                continue;
            }
            if (this.mot_a_trouver[index].localeCompare(c, 'fr', {sensitivity: 'base'}) == 0){
                this.mot[index] = this.mot_a_trouver[index]
                if(++this.foundcount == this.mot_a_trouver.length){
                    return 1;
                }
                break;
            }
        }

        // fin de comparaison
        if(index == this.mot.length){
            if(++this.errors >= this.max_errors){
                return 0;
            }
        }
        
        return ;
    }

    play(){
        const readline = require('readline');
        readline.emitKeypressEvents(process.stdin);
        process.stdin.setRawMode(true);

        const f = (str, key) => {
            if (key.ctrl && key.name === 'c') {
            process.stdin.pause()
            } else {
                console.log(`You pressed the "${str}" key`);
                var ketResult = this.keypressed(str);
                if(ketResult == 1){
                    this.show()
                    process.stdin.removeListener("keypress", f)
                    process.stdin.pause()
                    console.log("Gagnée !");
                }else if(ketResult == 0){
                    this.show()
                    process.stdin.removeListener("keypress", f)
                    process.stdin.pause()
                    console.log("Perdue...");
                }else{
                    this.show()
                    console.log("Taper une lettre")
                }
            }
        }
        
        let promise = new Promise((resolve, rejects)=>{
            process.stdin.on('keypress', f);
        })
        
        return promise

        // Ne pas oublier de faire process.stdin.removeListener("keypress", f)
        // afin de "nettoyer le handler"
    }
}

exports.Pendu = Pendu;