public class MillePattes extends AnimalAPattes{
    public MillePattes(String nom, int age) {
        super(nom, age);
        super.nbPattes = 1000;
    }

    public MillePattes(String nom) {
        super(nom);
        super.nbPattes = 1000;
    }

    @Override
    public String toString() {
        return super.toString() + " MillePattes";
    }
    
    public void crier() {
        System.out.println("[cri du mille-pattes] ...(silence)");
    }
}
