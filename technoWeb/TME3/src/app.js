// On s'assure que control-C nous permet d'interrompre
// l'ex ́ecution du programme
const readline = require('readline');
const random = require('random')

readline.emitKeypressEvents(process.stdin);
process.stdin.setRawMode(true);
process.stdin.on('keypress', (_str, key) => {
    if (key.ctrl && key.name == "c") {
        console.log("Quitting with control-c");
        process.exit();
    }
});
const pendu = require("./pendu.js")

new pendu.Pendu("POMME", 5).show()
readline.cursorTo(process.stdout, 0, 0)
readline.clearScreenDown(process.stdout)

const pomme = new pendu.Pendu("POMME", 5)
pomme.play()