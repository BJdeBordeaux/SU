public class Roue{

	private int diametre;

	public Roue(int d){
		diametre = d;
	}

	public Roue(){
		this(60);
	}

	public String toString(){
		return "Roue de diametre " + diametre + " cm.";
	}

	//Q26.8 modification
	// public int getDiametre(){
	// 	return diametre;
	// }
	public Roue clone(){
		return new Roue(diametre);
	}
}