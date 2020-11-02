public class PointNomme extends Point{
	private String name;


	public PointNomme(double x, double y, String name){
		super(x, y);
		this.name = name;
	}

	public PointNomme(String name){
		super();
		this.name = name;
	}

	public PointNomme(){
		super();
		this.name = "No name";
	}

	public String getNom(){
		return name;
	}

	public String toString(){
		return "PointNomme [ " + name + ", " + super.toString() + "]";
	}

	public void pn(){
		System.out.println("I'm only in pn");
	}

	// public boolean equals(Point p){
	// 	if(p == this){return true;}
	// 	if(p == null){return false;}
	// 	if(p.getClass() != this.getClass())
	// 		{return false;}
	// 	if(p.getX() != this.getX()){return false;}
	// 	if(p.getY() != this.getY()){return false;}
	// 	return true;
	// }

}