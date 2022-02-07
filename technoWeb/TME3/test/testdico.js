const assert = require("assert")
const dico = require("../src/dico.js")
const path = require('path')
const dicopath = path.join(path.dirname(__dirname), "dico.txt")

describe("Lire un dictionnaire", () => {
    it("sync", () => {
        let words = dico.litSync(dicopath, 5)
        assert.strictEqual(words[0], "ANGLE")
        assert.strictEqual(words[2], "MEUBLE")
    })
    it("promise", async () => {
        let words = await dico.lit(dicopath, 5)
        assert.strictEqual(words[0], "ANGLE")
        assert.strictEqual(words[2], "MEUBLE")
    })
    it("async", async () => {
        let words = await dico.litAsync(dicopath, 5)
        assert.strictEqual(words[0], "ANGLE")
        assert.strictEqual(words[2], "MEUBLE")
    })
})