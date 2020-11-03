public class Camion extends AMoteur{
    protected double volume;

    public Camion(double c, double e, double volume) {
        super(c, e);
        this.volume = volume;
    }

    @Override
    public String toString() {
        return super.toString() + " :: Camion [volume=" + volume + "]";
    }

    public void transporter(String materiaux, int km){
        if (enPanne()) {
            System.out.println("Plus d'essence");
        }else{
            System.out.println("Le camion n°" + getNumero() + 
            " a transporté " + materiaux + " sur " + km + "km.");
        }
        
    }
}
