public class Rectangle extends Shape {

    private double longueur, largeur;

    public Rectangle(double x, double y, double longueur, double largeur) {
        super(x, y);
        this.longueur = longueur;
        this.largeur = largeur;
    }

    public Rectangle() {
        super();
        longueur = 1;
        largeur = 1;
    }

    @Override
    public double surface() {
        return longueur*largeur;
    }

    @Override
    public String toString() {
        return super.toString() + 
        ", Rectangle de longueur : " + longueur + 
        ", largeur " + largeur + 
        " et de surface " + surface();
    }

    
}