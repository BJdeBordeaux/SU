public class Point{
	private double x,y;  //attributs prives

	public Point(double x2, double y2){ // constructeur 1
	// convention : le nom de la classe
		x = x2;
		y = y2;
	}

	public Point(double d){
		x = d;
		y = d;
	}

	public Point(){
		// x = Math.random()*10;
		// y = Math.random()*10;
		// the same as below
		this(Math.random()*10,Math.random()*10);//invocation du constructeur 1
	}

	public String toString(){
		return "["+x+", "+y+"]";
	}

	public Point add(Point p){
		//return new Point(x+p2.getX(), y+p2.getY());
		return new Point(x+p.x, y+p.y);
		// for an instance of the same class, privates attributes can be accessed
	}

	// if a method use x as parametre, this.x (instance) != x (parametre)
	
	public double getX(){	return x;	}
	public double getY(){	return y;	}

	public boolean egals(Point p){
		if(p == null){return false;}
		if(p.x == this.x && p.y == this.y){return true;}
		else{return false;}
	}
}