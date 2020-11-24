public class TestFigure {
    public static void main(String[] args) {
        Figure2D[] tab = new Figure2D[4];
        tab[0] = new Rectangle(10, 5);
        tab[1] = new Carre(4);
        tab[2] = new Ellipse(9, 7);
        tab[3] = new Cercle(6);
        for (Figure2D figure2d : tab) {
            System.out.println(figure2d.toString());
            System.out.println("surface = " + figure2d.surface());
            System.out.println("perimetre = " + figure2d.perimetre());
        }
    }
}
