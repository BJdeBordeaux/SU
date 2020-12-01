public class WVoyageur extends Wagon{

    private int nb_places;

    public WVoyageur(String marque) {
        super(marque);
        nb_places = 100;
    }

    @Override
    public String toString() {
        return "WVoyageur [marque=" + marque + ", numero_de_serie=" + numero_de_serie + "]";
    }

    public int getNb_places() {
        return nb_places;
    }

    public void setNb_places(int nb_places) {
        this.nb_places = nb_places;
    }
    
}
