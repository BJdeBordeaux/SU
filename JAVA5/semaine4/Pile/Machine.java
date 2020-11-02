public class Machine{

	// attributs
	private String nom;
	private int valeur;

	// constructeur sans paramètre
	public Machine(){
		this.valeur = (int)(Math.random()*21);
		this.nom = "Unnamed machine";
	}

	public String toString(){
		return this.nom + " " + this.valeur;
	}

}