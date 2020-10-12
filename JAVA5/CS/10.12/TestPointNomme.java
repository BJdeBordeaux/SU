public class TestPointNomme{
	public static void main(String[] args){
		Point pn1 = new PointNomme(1.,2., "toto");
		Point p1 = new Point(1,2);
		Point p2 = new Point(1,2);
		System.out.println(pn1.toString());
		//System.out.println(pn1.getNom());
		System.out.println(pn1.getClass());
		System.out.println(p1.getClass());
		System.out.println(pn1.equals(p1));
		System.out.println(p1.equals(pn1));
	}
}