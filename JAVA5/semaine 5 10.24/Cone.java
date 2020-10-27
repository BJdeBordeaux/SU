public class Cone{
	private double r, h;
	private static final double PI = 3.1415926897;
	private static int nbCones = 0;

	public Cone(double r, double h){
		this.r = r;
		this.h = h;
		nbCones++;
	}

	public Cone(){
		this(Math.random()*10, Math.random()*10);
	}

	public double getVolume(){
		return PI*r*r*h/3;
	}

	public String toString(){
		return String.format("[Cone r=%.3f h=%.3f V=%f]", r, h ,getVolume());
	}

	public static int getNbCones(){
		return nbCones;
	}
}