public class TestPion{
	public static void main(String[] args){
		Pion pa = new Pion("Atchoum");
		Pion pb = pa;
		pb.setNom("Dormeur");
		System.out.println(pa.getNom());
		//Q22.1.1 affichage : "Dormeur",
		// car les deux variables de type Pion référence le même objet
		
		//Q22.2.2
		pb.seDeplacer();
		// On veut bouger le Pion autrePion mais on aussi déplace unPion
		// car on a changé les coordonnées du Point.
		System.out.println(pa.toString());
		System.out.println(pb.toString());

		// //Q22.1.3
		// pa.setNom("Atchoum");
		// pb = pa.clone();
		// pb.setNom("Dormeur");
		// System.out.println(pa.getNom());	

		// //Q22.2.1 Oui, elles compilent toujours.		

		// //Q22.2.2
		// if we put it here and uncoment Q22.1.3 bloc, the Point will be different.
	}
}