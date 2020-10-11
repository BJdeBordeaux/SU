public class Bouteille{
	private double volume;

	public Bouteille(double volume){
		this.volume = volume;
	}

	public Bouteille(){
		this(1.5);
	}

	public void remplir(Bouteille b){
		this.volume += b.volume;
		b.volume = 0;
	}

	public void remplir(double v){
		this.volume += v;
	}

	public String toString(){
		return ("Volume du liquide dans la bouteille = " + volume);
	}

	public double getVolume(){
		return this.volume;
	}
}