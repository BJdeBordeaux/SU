public class TestPoint{
	public static void main(String[] args){
		Point p = new Point(2., 3.1);
		Point p2 = new Point(4.2);
		Point p3 = new Point();

		double px = p.getX();
		System.out.println("coord x de p: "+px);

		String str = p.toString();
		System.out.println("p: " + str);

		Point p4 = p.add(p3);
	}
}