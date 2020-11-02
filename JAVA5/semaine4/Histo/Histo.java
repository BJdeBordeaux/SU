public class Histo{
	private int[] hist;

	public Histo(){
		hist = new int[21];
		for(int i = 0; i< hist.length; i++){
			hist[i] = 0;
		}
	}

	public Histo(int[] t){
		this();
		for(int i = 0; i < t.length; i++){
			this.ajout_note(t[i]);
		}
	}

	public void ajout_note(int n){
		hist[n]++;
	}

	public void afficheHistogrammeTableau(){
		for(int i = 0; i < hist.length; i++){
			if(hist[i] != 0){
				System.out.print(hist[i] + "  ");
			}
		}
		System.out.println();
	}

	public void afficheHistogramme(){
		for(int i = 0; i < hist.length; i++){
			System.out.printf("%-2d| ", i);
			for(int j = 0; j < hist[i]; j++){
				System.out.print("*");	
			}
			System.out.println();		
		}
	}

	
	
}