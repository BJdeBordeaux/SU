public class TestHisto{
	public static void main(String[] args){
		System.out.println("Hello.");

		int[] tab = new int[150];
		for(int i = 0; i < tab.length; i++){
			tab[i] = (int)(Math.random()*21);
		}

		Histo histo = new Histo(tab);
		histo.afficheHistogrammeTableau();
		histo.afficheHistogramme();
	}
}