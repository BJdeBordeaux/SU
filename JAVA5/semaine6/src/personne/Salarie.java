public class Salarie extends Personne{
    private double salaire;

    public Salarie(String nom, double salaire) {
        super(nom);
        this.salaire = salaire;
    }

    public double getSalaire() {
        return salaire;
    }

    public double prime(){return 0.05*getNbEnfants()*salaire;}

    public void modifierNumTel(String numTel){
        super.numTel = numTel;
        System.out.println("Le salarié " + nom + " a pour numéro " + numTel);
    }
}
