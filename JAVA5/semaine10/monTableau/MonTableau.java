public class MonTableau {
    int[] tab;
    int lgRelle;

    public MonTableau(int taille) {
        tab = new int[taille];
        lgRelle = 0;
    }

    public void ajouter(int n) throws TabPleinException{
        lgRelle += 1;
        if (lgRelle >= tab.length) {
            throw new TabPleinException("Depassement des bornes a la position " + lgRelle + "\n");
        }
        tab[lgRelle-1] = n;
    }
}
