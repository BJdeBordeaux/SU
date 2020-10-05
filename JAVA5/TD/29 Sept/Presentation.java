public class Presentation{
	public static void main(String[] agrs){
		Personne p1 = new Personne("Paul", 25);
		Personne p2 = new Personne("Pierre", 37);
		System.out.println(p1);
		// System.out.println(p2);
		p2.sePresenter();

		int i;
		for(i = 0; i < 20; i++){
			p1.vieillir();
		}

		i = 0;
		while(i < 10){
			p2.vieillir();
			i++;
		}
		p1.sePresenter();
		p2.sePresenter();
	}
}