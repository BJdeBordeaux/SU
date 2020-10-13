public class TestTracteur{
	public static void main(String[] args){
		Roue ra = new Roue(120);
		Roue rb = new Roue(120);
		Roue rc = new Roue();
		Roue rd = new Roue();

		System.out.println(ra.toString());
		System.out.println(rc.toString());

		Cabine ca = new Cabine(50, "bleu");
		System.out.println(ca.toString());

		Tracteur ta = new Tracteur(ra, rb, rc, rd, ca);
		System.out.println(ta.toString());
		
		//Q26.8
		// t1.couleur == t2.couleur, car t1 et t2 référence à une même instance.
		// Il faut faire une copie de t1 et l'affecte à t2, au lieu de donner la même référence de t1 par une simple affection.
		Tracteur tb = ta;
		tb.peindre("rouge");
		System.out.println(ta.toString());
		tb = ta.clone();
		tb.peindre("blue");
		System.out.println(ta.toString());
		System.out.println(tb.toString());
	}
}