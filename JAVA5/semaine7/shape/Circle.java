public class Circle extends Shape {
    private double radius;

    public Circle() {
        super();
        radius = 1;
    }

    public Circle(double x, double y, double r) {
        super(x, y);
        radius = r;
    }

    @Override
    public String toString() {
        return super.toString() + " Rayon : " + radius + ", surface : " + surface();
    }

    @Override
    public double surface() {
        return radius*radius*Math.PI;
    }

    
}
