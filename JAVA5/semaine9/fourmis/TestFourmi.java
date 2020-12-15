public class TestFourmi {
    public static void main(String[] args) {
        // Fourmi[] fourmilliere = new Fourmi[5];
        Fourmi f4 = new Reine("majeste1");//Creation d'une variable de type Fourmi et qui fait reference a un objet Reine
        Reine f6 = new Reine("majeste2");//Creation d'une variable de type Reine et qui fait reference a un objet Reine
        // fourmilliere[0] = f6.engendreFourmis();
        // fourmilliere[1] = ((Reine) f4).engendreFourmis();
        f4.manger(new Nourriture("un peu de sucre"));
        f4.manger(new GeleeRoyale());
        Nourriture ng = new GeleeRoyale();
        f4.manger(ng);
    }
}
