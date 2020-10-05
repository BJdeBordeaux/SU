public class Segment{
	private int x;
	private int y;

	public Segment(int extX, int extY){
		x = extX;
		y = extY;
	}

	public int longueur(){
		if(x>=y){
			return x-y;
		}else{
			return y-x;
		}
	}

	public String toString(){
		return "Segment [" + x + ", " + y + "]";
	}
}