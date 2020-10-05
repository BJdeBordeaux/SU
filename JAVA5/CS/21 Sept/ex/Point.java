public class Point{
	private int x,y;
	public void initPtn(int x2, int y2){
		x=x2;
		y=y2;
	}
	public int getX(){
		return x;
	}
	public void affiche(){
		System.out.println("this is my point"+x+";"+y);
	}



	
}