import java.util.ArrayList;

public class Etudiant {
    private String nom;
    private int[] notes;
    private int lgRelle;
    private static ArrayList<Etudiant> etudiants = new ArrayList<Etudiant>();

    public Etudiant(String nom) {
        this.nom = nom;
        notes = new int[5];
        etudiants.add(this);
    }

    @Override
    public String toString() {
        String allNotes = "";
        for (int i = 0; i < lgRelle; i++) {
            allNotes += notes[i] + " ";
        }
        return "nom :" + nom + ", note : " + allNotes + "\n";
    }

    public void entrerNote(int note) throws TabNotesPleinException{
        if (lgRelle >= notes.length) {
            throw new TabNotesPleinException("Le tableau de notes de " + nom + " est plein.\n");
        }
        notes[lgRelle] = note;
        lgRelle += 1;
    }

    public static ArrayList<Etudiant> getEtudiants() {
        return etudiants;
    }

    public static void setEtudiants(ArrayList<Etudiant> etudiants) {
        Etudiant.etudiants = etudiants;
    }

    public String getNom() {
        return nom;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }

    
}
