public class Truc{

	private static int cpt = 0;
	private int num;

	public Truc(){
		cpt++;
		num = cpt;
	}

	public Truc(int x){
		num = x;
	}

	public static int getCpt(){return cpt;}
	public int getNum(){return num;}


}