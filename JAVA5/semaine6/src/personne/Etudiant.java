public class Etudiant extends Personne {
    private String cursus;

    public Etudiant(String n, String t, String cursus) {
        super(n,t);
        this.cursus = cursus;
    }

    public boolean estEnL2(){return cursus.equals("L2");}
}
