public class Point{
	private int posx, posy;

	public Point(int x, int y){
		this.posx = x;
		this.posy = y;
	}

	public Point(){
		this((int)(Math.random()*11),(int)(Math.random()*11));
	}

	public void setPosx(int x){
		this.posx = x;
	}

	public void setPosy(int y){
		this.posy = y;
	}

	public int getPosx(){
		return this.posx;
	}

	public int getPosy(){
		return this.posy;
	}

	public String toString(){
		return "(" + posx + ", " + posy +")";
	}

	public double distance(Point p){
		double dx = (double) Math.abs(this.posx - p.posx); 
		double dy = (double) Math.abs(this.posy - p.posy); 
		return Math.sqrt(dx*dx + dy*dy);
	}

	public void deplaceToi(int newx, int newy){
		this.posx = newx;
		this.posy = newy;
	}
}