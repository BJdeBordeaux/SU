public class FeuTricolore{
	private Lampe lampeVerte;
	private Lampe lampeOrange;
	private Lampe lampeRouge;

	public FeuTricolore(){
		lampeVerte = new Lampe();
		lampeOrange = new Lampe();
		lampeRouge = new Lampe();
	}

	public FeuTricolore(Lampe v, Lampe o, Lampe r){
		lampeVerte = v;
		lampeOrange = o;
		lampeRouge = r;
	}

	// //Do not use it, it is false
	// public FeuTricolore(Lampe l){
	// 	lampeVerte = l;
	// 	lampeOrange = l;
	// 	lampeRouge = l;
	// }
}