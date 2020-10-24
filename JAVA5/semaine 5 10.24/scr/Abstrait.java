//note
public abstract class Abstrait{
	private String nom;

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
}