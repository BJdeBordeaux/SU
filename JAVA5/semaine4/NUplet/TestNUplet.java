public class TestNUplet{
	public static void main(String[] args){
		NUplet a = new NUplet(5, 3);
		NUplet b = new NUplet(7, 8, 9);
		NUplet c = new NUplet(0);

		System.out.println(a.toString());
		System.out.println(a.somme());
		System.out.println(b.toString());
		System.out.println(b.somme());
		System.out.println(c.toString());
		System.out.println(c.somme());

		int[] tabc = {1, 2, 3};
		NUplet u = new NUplet(tabc);
		tabc[0] = 50;
		System.out.println(u.toString());
		
		//Q28.4
		//affiche (50, 2, 3)
		//Solution : Il faut écrire 
		// tab = t.clone();
		// dans le constructeur

		NUplet ud = new NUplet(4, 5, 6);
		int [] tdef = ud.getTab();
		tdef[0] = 70;
		System.out.println(ud.toString());

		//Q28.5
		//affiche (70, 5, 6)
		//Solution : Il faut écrire 
		// return tab.clone();
		// dans getTab()
	}
}