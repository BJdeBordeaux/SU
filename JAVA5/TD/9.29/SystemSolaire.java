public class SystemSolaire{
	public static void main(String[] args){
		Planete m = new Planete("Mercure", 2439.7);
		Planete t = new Planete("Terre", 6378.137);
		System.out.println(m.toString());
		System.out.println(t.getRayon());
		System.out.println(t);

		Planete p1 = new Planete("Planete 1");
		Planete p2 = new Planete("Planete 2");
		System.out.println(p1.toString());		
		System.out.println(p2.toString());		
	}
}