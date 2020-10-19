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

}