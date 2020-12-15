/**
 * TestEtudiants
 */
public class TestEtudiants {

    public static void main(String[] args) {
        int note;
        Etudiant curEtudiant = null;
        for (int i = 0; i < args.length; i++) {
            try {
                note = Integer.parseInt(args[i]);
                // System.out.print(note + " est une note, ");
                curEtudiant.entrerNote(note);
            } catch (NumberFormatException e) {
                // System.out.print("\n" + args[i] + " est un nom,");
                System.out.println(curEtudiant);
                curEtudiant = new Etudiant(args[i]);
            } catch (TabNotesPleinException e) {
                System.out.print("Le tableau de " +curEtudiant.getNom() + " est plein\n" );
            }
        }
        System.out.println("Done.");
        // Anna 12 13 7 15 Tom Arthur 9 12 15 0 13 12 Karim 15 8 11 12 10 Memossa 12 6 18 10 12 6
    }
}