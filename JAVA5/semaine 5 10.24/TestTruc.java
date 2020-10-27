public class TestTruc{
	public static void main(String[] args){
		Truc na = new Truc();
		System.out.println(na.getCpt());

		Truc nb = new Truc(25); 
		System.out.println(na.getCpt() + " " + nb.getCpt());

		Truc nc = new Truc();
		System.out.println(na.getNum() + " " + nb.getNum() + " " + nc.getNum());
		System.out.println(na.getCpt() + " " + nb.getCpt() + " " + nc.getCpt());
	}
}