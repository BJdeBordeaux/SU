public class Vector{
	private double x, y, z;

	public Vector(double c1, double c2, double c3){
		x = c1;
		y = c2;
		z = c3;
	}

	public Vector(){
		this((Math.random()*10), (Math.random()*10), (Math.random()*10));	
	}

	public String toString(){
		return "(" + x + ", " + y + ", " + z + ")";
	}

	public Vector sommeVector(Vector v){
		return new Vector(x + v.x, y + v.y, z + v.z);
	}

	public static Vector somme(Vector va, Vector vb){
		return new Vector(va.x + vb.x, va.y + vb.y, va.z + vb.z);
	}
	
}