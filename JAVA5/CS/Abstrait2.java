public class Abstrait2 extends Abstrait{
	private double x, y;

	public Abstrait2(String nom){
		super(nom);
		x = Math.random();
		y = Math.random();
	}

	public void affiche(){
		System.out.println("Hello, I'm " + super.getNom());
	}

	public void sus(int a){
		System.out.println(a + " from "+ this.getClass());
	}

	public void sus(double a){
		System.out.println(a + " from "+ this.getClass());
	}

	public void mm(A a){
		System.out.println(a.getClass()+ " from "  + this.getClass() + ", " + this.nom);
	}

	// public void mm(B b){
	// 	System.out.println(b.getClass()+ " from "  + this.getClass() + ", " + this.nom);
	// }
}