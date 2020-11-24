import java.util.ArrayList;
public class MainShape {
    public static void main(String[] args) {
        Circle ca, cb;
        ca = new Circle();
        cb = new Circle(1, 1, 3);
        System.out.println(ca.toString() + "\n" + cb.toString());

        // Q 48.5
        int taille = 12;
        double aire = 0;
        Shape [] shapes = new Shape[taille];
        for (int i = 0; i < shapes.length; i+=4) {
            shapes[i] = new Circle();
            shapes[i+1] = new Circle(1, 3, 5);
            shapes[i+2] = new Rectangle();
            shapes[i+3]  = new Rectangle(2, 3, 4, 5);
        }
        for (Shape shape : shapes) {
            if(shape == null)continue;
            aire += shape.surface();
            System.out.println(shape.toString());
        }
        System.out.println("aire total = " + aire + ".\n");
        
    }

    // Q 48.1 la classe Circle herite des variable d'instance x, y de la classe Shape 
    // et la methode toString() redefinie dans Shape
    // En ce qui concerne la methode abstraite surface(), cette derniere doit etre redefinie dans les classes filles de Shape

    // Q 48.2
    // La methode abstraite surface() n'est pas redefinie dans la classe Circle,
    // Redefinir surface() dans la classe Circle 
    // Ou declarer la classe Circle comme abstraite
    // Rappel : toutes les classes contenant une methode abstraite doivent etre classes abstraites
}
