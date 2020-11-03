public class AMoteur extends Vehicule {
    protected double capacite, essence;

    public AMoteur(double capacite, double essence) {
        super();
        this.capacite = capacite;
        this.essence = essence;
    }

    @Override
    public String toString() {
        return super.toString() + " :: AMoteur [capacite=" + capacite + ", essence=" + essence + "]";
    }

    public void approvisionner(double nbLitres){
        this.essence += nbLitres;
    }

    public boolean enPanne(){
        return (essence == 0);
    }

    
}
