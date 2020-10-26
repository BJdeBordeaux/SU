public class TestPointNomme{
	public static void main(String[] args){
		Point pn1 = new PointNomme(1.,2., "toto");
		Point p1 = new Point(1,2);
		Object p2 = p1;
		Point p3 = new Point(1,2);
		// System.out.println(pn1.toString());
		//System.out.println(pn1.getNom());
		// System.out.println(pn1.getClass());
		// System.out.println(p1.getClass());
		// System.out.println(pn1.equals(p1));
		// System.out.println(p1.equals(pn1));
		System.out.println(p1.equals(p2));
		System.out.println(p2.equals(p1));

		// pn1.pn();  cannot find symbol
	}
}