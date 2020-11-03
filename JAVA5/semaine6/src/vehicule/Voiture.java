public class Voiture extends AMoteur {
    protected int nbPlace;

    public Voiture(double capacite, double essence, int np) {
        super(capacite, essence);
        nbPlace = np;
    }

    @Override
    public String toString() {
        return super.toString() + " :: Voiture";
    }
    
    public void transporter(int n, int km){
        if(enPanne()){System.out.println("Plus d'essence!");
        }else{
            System.out.println("Le voiture n°" + super.getNumero() + 
            " a transporté " + n + " personne sur " + km + "km.");
        }
    }
}
