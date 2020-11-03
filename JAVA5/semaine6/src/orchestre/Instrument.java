public class Instrument {
    protected double poids, prix;

    public Instrument(double poids, double prix) {
        this.poids = poids;
        this.prix = prix;
    }

    @Override
    public String toString() {
        return "Instrument [poids=" + poids + ", prix=" + prix + "]";
    }

    protected void jouer(){this.jouer();}
}
