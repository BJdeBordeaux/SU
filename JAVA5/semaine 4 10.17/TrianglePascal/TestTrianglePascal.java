public class TestTrianglePascal{
	public static void main(String[] args){
		// initiailise
		TrianglePascal pa = new TrianglePascal(0);
		pa.remplirTriangle();

		TrianglePascal pb = new TrianglePascal(1);
		pb.remplirTriangle();

		TrianglePascal pc = new TrianglePascal(5);
		pc.remplirTriangle();
		
		// check
		System.out.println(pa.toString());
		System.out.println(pb.toString());
		System.out.println(pc.toString());

	}
}