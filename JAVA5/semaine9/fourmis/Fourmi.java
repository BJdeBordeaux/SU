public class Fourmi{
    protected String nom;

    public Fourmi(String nom) {
        this.nom = nom;
    }

    public void manger(Nourriture n) {
        System.out.println(nom + " mange " + n);
    }
}