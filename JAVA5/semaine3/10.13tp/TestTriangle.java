public class TestTriangle{
	public static void main(String[] args){
		Point pa = new Point(0,0);
		Point pb = new Point(3,0);
		Point pc = new Point(0,4);
		Triangle ta = new Triangle(pa, pb, pc);
		System.out.println(ta.toString());
		System.out.println(ta.getPerimetre());
	}
}