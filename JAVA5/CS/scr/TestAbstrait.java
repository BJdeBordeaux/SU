public class TestAbstrait{
	public static void main(String[] args){
		Abstrait a = new Abstrait2("LI");
		System.out.println(a.toString());
		a.affiche();

		Abstrait2 ab = new Abstrait2("ab 2,2");
		Abstrait2 ac = new Abstrait3("ac 2,3");
		Abstrait3 ad = new Abstrait3("ad 3,3");

		// a.sus(5);
		// ab.sus(5);
		// ac.sus(5);

		// a.sus(5.);
		// ab.sus(5.);
		// ac.sus(5.);

		// System.out.println(a.getClass());
		// System.out.println(ab.getClass());
		// System.out.println(ac.getClass());


	}
}