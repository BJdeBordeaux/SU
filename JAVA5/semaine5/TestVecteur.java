public class TestVecteur{
	public static void main(String[] args){
		Vecteur va = new Vecteur(1, 2);
		Vecteur vb = new Vecteur(1, 2);
		if(va.x == vb.x && va.y == vb.y){
			System.out.println("v1 égal v2");
		}

		if(va.id == vb.id){
			System.out.println("los dos puntos tienen la misma identidad");
		}

		System.out.println("Compteur : " + va.getCpt());
		System.out.println("Compteur (2): " + Vecteur.getCpt());
		// System.out.println("Compteur (3): " + va.cpt);
	}
}