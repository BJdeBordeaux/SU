public class TestComplexe{
	public static void main(String[] args){
		Complexe a = new Complexe(0,1);
		Complexe b = a.multiplication(a);
		System.out.println(b.toString());
		System.out.println(b.estReel());
		Complexe c = new Complexe(1,1);
		Complexe d = new Complexe(2,2);
		b = c.multiplication(d);
		System.out.println(b.toString());
		b = c.addition(d);
		System.out.println(b.toString());
		System.out.println(b.estReel());
		Complexe e = new Complexe(2,0);
		System.out.println(e.estReel());
	}
}
