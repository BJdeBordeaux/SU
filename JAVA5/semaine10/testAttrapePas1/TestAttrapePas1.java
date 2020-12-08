public class TestAttrapePas1 {
    
    public static void main(String[] args) {
        System.out.println("La moyenne est : " + moyenne(args));
        
    }

    public static double moyenne(String[] tab) {
        double res = 0;
        int nbNote = 0;
        int note, i;
        for (i = 0; i < tab.length; i++) {
            try {
                note = Integer.parseInt(tab[i]);
                res += note;
                nbNote++;
            } catch (NumberFormatException e) {
                System.out.println("Invalid input. La note de position " + (i+1) + " n'est pas un entier.");
            }
        }
        
        return res/=nbNote;
    }

    
}
