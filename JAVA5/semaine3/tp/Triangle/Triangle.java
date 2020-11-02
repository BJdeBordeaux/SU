public class Triangle{
	private Point pa, pb, pc;

	public Triangle(Point a, Point b, Point c){
		pa = a;
		pb = b;
		pc = c;
	}

	public Triangle(){
		this(new Point(), new Point(), new Point());
	}

	public double getPerimetre(){
		double ab = pa.distance(pb);
		System.out.println("ab = " + ab);
		double bc = pb.distance(pc);
		System.out.println("bc = " + bc);
		double ca = pc.distance(pa);
		System.out.println("ca = " + ca);
		return ab+ bc + ca;
	}

	public String toString(){
		return "[" + pa.toString() + ", " + pb.toString() + ", " + pc.toString() + "]";
	}

	//Q25.5
	// public boolean equals(Triangle t);
	// D'abord, prendre un Point pa du Triangle this et comparer si un des 3 Point de Triangle t a les mêmes coordonnées avec lui, sans dinstinguer l'ordre
	// Ensuite répéter cette procédure pour les deux Point du Triangle
	// Enfin, comparer l'aire des deux Triangle (en prévention que deux Point d'un Triangle sont confondu)
	// Si un des étapes ne passe pas, les deux Triangle ne sont pas égaux, donc retourne false;
	// Sinon, retourne true;
}