public class TestFeuTricolore{
	public static void main(String[] args){
		//Q23.2
		FeuTricolore fa = new FeuTricolore(new Lampe(),new Lampe(),new Lampe());
		Lampe v = new Lampe();
		Lampe o = new Lampe();
		Lampe r = new Lampe();
		FeuTricolore fb = new FeuTricolore(v,o,r);

		//Q23.3
		//car verte, orange et rouge (de type Lampe) référencent à une même instances,
		// alors que ces variables doivent être différentes selon le sujet.
		FeuTricolore fc = new FeuTricolore(v);

		//Q23.4
		//En effet, les trois arguments qu'on donne au constructeur référencent à une même instance
		// car lp2 = lp1 cela ne crée pas une nouvelle instance, mais crée une nouvelle variable référençant à une instance existante
		// Ensuite, cette instance est passée en argument pour le constructeur.
	}
}