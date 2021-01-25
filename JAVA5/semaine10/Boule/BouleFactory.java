public class BouleFactory {
    public final static String[] couleurs = {"rouge" , "jaune" , "bleue" , "verte" , "orange" , "violette" };
    public static Boule build() {
        return new Boule(couleurs[(int)(Math.random()*couleurs.length)]);
    }
}
