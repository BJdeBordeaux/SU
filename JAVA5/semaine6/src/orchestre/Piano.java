public class Piano extends Instrument{
    
    public Piano(double poids, double prix) {
        super(poids, prix);
    }
    public void jouer(){
        System.out.println("Le piano joue.");
    }  
}