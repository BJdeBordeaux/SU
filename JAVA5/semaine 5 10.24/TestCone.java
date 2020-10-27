public class TestCone{
	public static void main(String[] args){
		System.out.println(Cone.getNbCones());
		Cone ca = new Cone();
		Cone cb = new Cone(1, 3);
		System.out.println(ca.toString());
		System.out.println(cb.toString());
		System.out.println(Cone.getNbCones());
	}
}