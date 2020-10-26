public class Abstrait3 extends Abstrait2{
	private int num;

	public Abstrait3(String nom){
		super(nom);
		num = (int)(Math.random()*20);
	}

	public void sus(int a){
		System.out.println(a + " from "+ this.getClass());
	}

	public void mm(D d){
		System.out.println(d.getClass()+ " from " this.getClass() + ", " + this.nom);
	}
}