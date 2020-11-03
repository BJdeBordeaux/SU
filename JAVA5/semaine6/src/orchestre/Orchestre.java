public class Orchestre {
    private int nbInstruments;
    private Instrument[] tabInstruments;

    public Orchestre() {
        nbInstruments = 0;
        tabInstruments = new Instrument[20];
    }

    public void ajouterInstrument(Instrument i){
        tabInstruments[nbInstruments] = i;
        nbInstruments++;
    }

    public void jouer(){
        for(int i = 0; i < nbInstruments; i++){
            tabInstruments[i].jouer();
        }
    }
}
