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

// readline.cursorTo(process.stdout, 0, 0)
// readline.clearScreenDown(process.stdout)
const dico = require("./dico.js")
const path = require('path')
const dicopath = path.join(path.dirname(__dirname), "dico.txt")
let min_mot_length = 5

const init = async (dico_path) => {
    let mots = await dico.lit(dico_path, min_mot_length)
    let mot_cible = mots[random.int(0, mots.length-1)]
    const game = new pendu.Pendu(mot_cible, min_mot_length)
    game.play()
}

init("./dico.txt")

