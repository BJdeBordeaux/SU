public class Vache extends AnimalAPattes{

    public Vache(String nom, int age) {
        super(nom, age);
        super.nbPattes = 4;
    }

    public Vache(String nom) {
        super(nom);
        super.nbPattes = 4;
    }

    @Override
    public String toString() {
        return super.toString() + " Vache";
    }
    
    public void crier() {
        System.out.println("[cri de la vache] Mouuuu");
    }
}
