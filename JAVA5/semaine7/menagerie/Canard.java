public class Canard extends AnimalAPattes{


    public Canard(String nom, int age) {
        super(nom, age);
        super.nbPattes = 2;
    }


    public Canard(String nom) {
        super(nom);
        super.nbPattes = 2;
    }


    @Override
    public String toString() {
        return super.toString() + " Canard";
    }
    
    public void crier() {
        System.out.println("[cri du canard] Gaga ... gaga ");
    }

}
