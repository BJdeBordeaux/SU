public class Couple{
	private int x, y;

	public Couple(int x, int y){
		this.x = x;
		this.y = y;
	}

	public Couple addition(Couple c){
		Couple a = new Couple(this.x + c.x, this.y + c.y);
		return a;
	}

	public String toString(){
		return "(" + x + ", " + y + ")";
	}
}