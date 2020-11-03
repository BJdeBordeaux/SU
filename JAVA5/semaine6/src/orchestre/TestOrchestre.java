public class TestOrchestre {
    public static void main(String[] args) {
        Instrument g = new Guitare(2, 2000);
        Instrument p = new Piano(3, 3000);
        Instrument t = new Trompette(5, 5000);
        Orchestre o = new Orchestre();
        o.ajouterInstrument(g);
        o.ajouterInstrument(p);
        o.ajouterInstrument(t);
        o.jouer();
    }
}
