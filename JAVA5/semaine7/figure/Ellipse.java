public class Ellipse extends Figure2D{
    private double a, b;

    public Ellipse(double a, double b){
        super();
        this.a = a; this.b = b;
    }

    public double surface(){
        return a*b*Math.PI;
    }

    public double perimetre(){return Math.PI*Math.sqrt((a*a + b*b)/2);}
    
}