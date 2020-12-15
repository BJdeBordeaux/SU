public class Reine extends Fourmi{
    private int cpt;

    public Reine(String nom) {
        super(nom);
    }
    
    public Fourmi engendreFourmis(){
        cpt += 1;
        return new Ouvrier(nom+cpt);
    }

    public void manger(Nourriture n) {
        System.out.println(nom + " (Reine) mange de " + n);
    }
}
