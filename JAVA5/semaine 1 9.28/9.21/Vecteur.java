public class Vecteur{
	private double x,y;

	public Vecteur(double x, double y){
		this.x = x;
		this.y = y;
	}

	public Vecteur(){
		this(Math.random()*50, Math.random()*50);
	}

	public String toString(){
		return"[ " + this.x + ", " + this.y + "]";
	}

	public double Norme(){
		double norme = Math.sqrt(Math.pow(x,2) + Math.pow(y,2));
		System.out.println("norme = " + norme);
		return norme;
	}

	public Vecteur ProduitScalaire(double n){
		return new Vecteur(x*n, y*n);
	}
}