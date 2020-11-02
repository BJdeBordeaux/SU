public class Cabine{

	private int volume;
	private String couleur;

	public Cabine(int v, String c){
		volume = v;
		couleur = c;
	}

	public String toString(){
		return "Cabine de volume " + volume + "m3 et de couleur " + couleur + "."; 
	}

	public void setCouleur(String c){
		couleur = c;
	}

	//Q26.8 modification
	// public int getVolume(){
	// 	return volume;
	// }
	// public String getCouleur(){
	// 	return couleur;
	// }
	public Cabine clone(){
		return new Cabine(volume, couleur);
	}
}