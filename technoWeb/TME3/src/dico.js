const fs = require("fs")

function litSync(filepath, minlength) {
    minlen = minlength || 0
    return fs.readFileSync(filepath).toString().split("\n").filter((s) => s.length >= minlength);
}
// console.log(litSync("dico.txt", 3))

async function lit(filepath, minlength) {
    minlen = minlength || 0
    return new Promise((resolve, rejects) => {
            data = fs.readFile(filepath, 'utf8', (err, data)=>{
                if(err){
                    console.log(err);
                    rejects(err);
                }else{
                    let dataTab = data.toString().split("\n").filter((s) => s.length >= minlength);
                    resolve(dataTab);
                }
            });
    });
}
// console.log(lit("dico.txt"))

async function litAsync(filepath, minlength) {
    minlength = minlength || 0
    let data = await fs.promises.readFile(filepath);
    return Promise.resolve(data.toString().split("\n").filter((s) => s.length >= minlength));
}
// console.log(litAsync("dico.txt", 3))

exports.litSync = litSync;
exports.lit = lit;
exports.litAsync= litAsync;