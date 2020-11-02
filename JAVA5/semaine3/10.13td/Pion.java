public class Pion{
	private String nom;

	// //Q22.1	
	// private double posx;
	//Q22.2
	private Point posx;

	public Pion(String n){
		nom = n;

		// //Q22.1
		// posx = Math.random();

		//Q22.2
		posx = new Point();
	}

	public void setNom(String n){
		nom = n;
	}

	public String getNom(){
		return nom;
	}

	//Q22.1.2
	public Pion clone(){
		return new Pion(nom);
	}

	public void seDeplacer(){
		posx.bouger();
	}

	public String toString(){
		return "nom, posx" + nom + ", [" + posx.getX() + ", " + posx.getY() + "].";
	}

}