public class EntierBorne {
    private int entier;

    public EntierBorne(int entier) throws HorsBorneException{
        verifier(entier);
        this.entier = entier;
    }

    @Override
    public String toString() {
        return "EntierBorne [entier=" + entier + "]";
    }

    public EntierBorne somme(EntierBorne i) throws HorsBorneException{
        int newEntier = this.entier + i.entier;
        verifier(newEntier);
        return new EntierBorne(this.entier + i.entier);
    }

    public EntierBorne divPar(EntierBorne i) throws HorsBorneException{
        int newEntier = (int) (this.entier/i.entier);
        verifier(newEntier);
        return new EntierBorne(newEntier);
    }

    public EntierBorne factorielle() throws HorsBorneException{
        int cpt = this.entier;
        int res = this.entier;
        if(cpt <= 1){// On ignore les entiers negatifs
            return new EntierBorne(1);
        }
        while (cpt>1) {
            cpt -= 1;
            res *= cpt;
            verifier(cpt);
        }
        return new EntierBorne(res);
    }

    public void verifier(int i) throws HorsBorneException{
        if (i >= 10000 || i <= -10000){
            throw new HorsBorneException("L'entier " + i + " est hors borne.");
        }
    }    
}
