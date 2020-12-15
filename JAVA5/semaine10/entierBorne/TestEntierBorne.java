public class TestEntierBorne {
    public static void main(String[] args) {
        try {
            int a = Integer.parseInt(Clavier.saisirLigne("Veuillez saisir un entier"));
            EntierBorne eb = new EntierBorne(a);
            int b = Integer.parseInt(Clavier.saisirLigne("Veuillez saisir un autre entier"));
            EntierBorne ebb = new EntierBorne(b);
            EntierBorne ec = eb.somme(ebb);
            System.out.println(ec);
            EntierBorne ed = eb.divPar(ebb);
            System.out.println(ed);
            EntierBorne ef = eb.factorielle();
            System.out.println(ef);
        } catch (NumberFormatException e) {
            try {
                Thread.sleep(5000);
            } catch (InterruptedException e2) {
                System.out.println("I caught a InterruptedException.");
            }
        } catch (HorsBorneException e){
            System.err.println(e.getMessage());
            System.out.println("The programme terminated.");
        }
        
        
    }
}
