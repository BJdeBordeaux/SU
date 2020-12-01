import java.util.ArrayList;

public class Train {
    private Motrice motrice;
    private ArrayList<Wagon> elemTrains;

    public Train(Motrice m) {
        this.motrice = m;
        this.elemTrains = new ArrayList<Wagon>();
    }

    public void ajouter(Wagon w) {
        elemTrains.add(w);
    }

    @Override
    public String toString() {
        String s = "";
        for (Wagon wagon : elemTrains) {
            s += wagon.toString() + "\n";
        }
        return "Train [elemTrains=" + s + ", motrice=" + motrice + "]";
    }

    public double poids() {
        double poids = 0;
        for (Wagon wagon : elemTrains) {
            if(wagon instanceof WMarchandise){
                poids += ((WMarchandise) wagon).getPoids_max();
            }
        }
        return poids;
    }

    public int nbPlace() {
        int nbPlace = 0;
        for (Wagon wagon : elemTrains) {
            if(wagon instanceof WVoyageur){
                nbPlace += ((WVoyageur) wagon).getNb_places();
            }
        }
        return nbPlace;
    }
}
