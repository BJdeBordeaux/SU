//note
public abstract class Abstrait{
	protected String nom;

	public Abstrait(String nom){
		this.nom = nom;
	}

	public String getNom(){
		return nom;
	}

	public String toString(){
		return nom + ": ";
	}

	public abstract void affiche();

	public void sus(int a){
		System.out.println(a + " from "+ this.getClass());
	}

	public void sus(double a){
		System.out.println(a + " from "+ this.getClass());
	}
}