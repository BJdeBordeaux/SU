public class Boa extends AnimalSansPattes {

    public Boa(String nom, int age) {
        super(nom, age);
    }
    
    public Boa(String nom) {
        super(nom);
    }

    @Override
    public String toString() {
        return super.toString() + " Boa";
    }
    
    public void crier() {
        System.out.println("[cri du boa] Sssss");
    }
}
