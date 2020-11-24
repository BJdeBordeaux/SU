public class Rectangle extends Figure2D{
    public double longueur, largeur;

    public Rectangle(double la, double lb){
        super();
        longueur = la;
        largeur = lb;
    }
    
    public double surface(){
        return longueur * largeur;
    }
    public double perimetre(){
        return 2 * (longueur + largeur);
    }
}