public class Chien extends Mammifere{
    public void aboyer() {System.out.println("Ouaff\n");}
    
    public static void main(String[] args) {
        Chien ca = new Chien();
        Mammifere ma = ca;
        ca = (Chien) ma; // cast
        
        // ca = ma; // it does not work
        // une variable de la classe Chien ne peut pas referencer
        // un objet de la super-classe Mammifere
        
        Mammifere mb = new Mammifere();
        
        Chien cb = (Chien) mb; // a la compilation pas d'erreur
        //mais il y a une erreur a l'execution
    }
}
