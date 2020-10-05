public class Personne{
	private String nom;
	private int age;

	public Personne(String n, int a){
		nom = n;
		age = a;
	}

	public String toString(){
		return "My name is " + nom + " et I'm " + age + ".";
	}

	public void sePresenter(){
		System.out.println("Bonjour, " + toString());
	}

	public int getAge(){
		return age;
	}

	public void vieillir(){
		age++;
	}
	
}