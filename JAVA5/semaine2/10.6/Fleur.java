public class Fleur{
	private String nom;
	private String couleur;

	// public Fleur(String name, String couleur){
	// 	nom = name;
	// 	this.couleur = couleur;
	// }

	// public Fleur(String nom){
	// 	this(nom,"rouge");
	// }

	public String toString(){
		return nom + " de couleur " + couleur;
	}

	public  String getNom(){
		return nom;
	}

	// public Fleur(String couleur){
	// 	this("Marguerite", couleur);
	// }

	/*public Fleur(){
		couleur = "rouge";
		this("Rose"); //should be the fisrt line in the statement
	}*/
}