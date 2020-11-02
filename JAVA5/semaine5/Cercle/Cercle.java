public class Cercle{
    public static final double PI = 3.14159;
    private static int nbCercles = 0;
    public final int numero;
    private int rayon;

    public Cercle(int r){
        rayon = r;
        nbCercles++;
        numero = nbCercles;
    }

    public double surface(){return PI*rayon*rayon;}
    public static int getNbCercles(){return nbCercles;}
}