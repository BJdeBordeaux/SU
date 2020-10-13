public class Point{
	//Q22.2
	private double x,y;

	public Point(){
		x = Math.random();
		y = Math.random();
	}

	public void bouger(){
		x = Math.random();
		y = Math.random();
	}

	public double getX(){
		return x;
	}

	public double getY(){
		return y;
	}
}