package point;

public class TestPoint {
    public static void main(String[] args) {
        Point p1 = new Point(5, 3);
        Point p2 = new Point(5, 3);
        Point p3 = p1;
        Point p4 = new Point(1, 1);
        System.out.println("p1 = p2 : " + p1.equals(p2));
        System.out.println("p1 = p3 : " + p1.equals(p3));
        System.out.println("p1 = p4 : " + p1.equals(p4));
    }
}
