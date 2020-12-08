public class TestAttrapePas3 {
    
    public static void main(String[] args) {
        try {
            System.out.println("La moyenne est : " + moyenne(args));
        } catch (AucunNoteException e) {
            System.out.println(e.getMessage() + e);
        }
        
    }

    public static double moyenne(String[] tab) throws AucunNoteException{
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
        if (nbNote == 0) {
            throw new AucunNoteException();
        }
        return res/=nbNote;
    }

}
