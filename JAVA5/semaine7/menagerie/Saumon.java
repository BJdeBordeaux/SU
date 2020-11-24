public class Saumon extends AnimalSansPattes{

    public Saumon(String nom, int age) {
        super(nom, age);
    }

    public Saumon(String nom) {
        super(nom);
    }
    
    @Override
    public String toString() {
        return super.toString() + " Saumon";
    }
    
    public void crier() {
        System.out.println("[cri du saumon] Bouuuu bou");
    }
}
