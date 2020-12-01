public class WMarchandise extends Wagon {

    private double poids_max;
    public WMarchandise(String marque) {
        super(marque);
        poids_max = 5000.;
    }

    public double getPoids_max() {
        return poids_max;
    }

    public void setPoids_max(double poids_max) {
        this.poids_max = poids_max;
    }
    
    
}
