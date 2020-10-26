public class Abstrait3 extends Abstrait2 implements noForm2{
	private int num;

	public Abstrait3(String nom){
		super(nom);
		num = (int)(Math.random()*20);
	}

	public void sus(int a){
		System.out.println(a + " from "+ this.getClass());
	}

	public void mm(B b){
		System.out.println(b.getClass()+ " from " + this.getClass() + ", " + this.nom);
	}	
}