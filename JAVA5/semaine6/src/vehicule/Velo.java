public class Velo extends Vehicule{
    protected double vitesse;

    public Velo(double v, int np) {
        super();
        vitesse = v;
    }

    @Override
    public String toString() {
        return super.toString() + " :: Velo [vitesse=" + vitesse + "]";
    }

    public void transporter(String depart, String arrivee){
        System.out.println("Le vélo n°" + super.getNumero() + 
        " a roulé de " + depart + " à " + arrivee + ".");
    }
}
