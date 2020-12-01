package submarine;

public class SousMarin implements Submarine, Echolocation {

    @Override
    public void seDeplacer() {
        System.out.println("Le sous-marin se deplace.");
    }

    @Override
    public void ecouterSon() {
        System.out.println("Le dauphin ecoute le son.");
    }

    @Override
    public void envoyerSon() {
        System.out.println("Le dauphin envoie le son.");
    }
    
}
