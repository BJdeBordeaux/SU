public class TestCercle{
    public static void main(String[] args){
        Cercle c = new Cercle(3);
        System.out.println(Cercle.PI);
//        System.out.println(Cercle.nbCercles);
        System.out.println(Cercle.getNbCercles());
//        System.out.println(Cercle.numero);
//        System.out.println(Cercle.rayon);
//        System.out.println(Cercle.surface());
        Cercle cb = new Cercle(2);
        Cercle cc = cb;
        Cercle cd = new Cercle(2);

    }
}