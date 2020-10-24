public class TestPile{
	public static void main(String[] args){
		// initiailise
		Machine ma = new Machine();
		Machine mb = new Machine();
		Machine mc = new Machine();
		Pile pa = new Pile();

		pa.empiler(ma);
		pa.empiler(mb);
		
		// check
		System.out.println(pa.toString());

		pa.depiler();
		System.out.println(pa.toString());

		pa.depiler();
		System.out.println(pa.toString());

	}
}