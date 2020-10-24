public class Pile{
	// attributs
	private Machine[] pile;

	public Pile(){
		pile = new Machine[20]; 
		for(int i = 0; i<pile.length; i++){
			pile[i] = null;
		}
	}

	public Pile(int n){
		pile = new Machine[n]; 
		for(int i = 0; i<pile.length; i++){
			pile[i] = null;
		}
	}

	public void empiler(Machine m){
		if(this.estPleine()){
			System.out.println("Sorry, the pile if full.");
		}else{
			int i = 0;
			while(pile[i] != null){
				i++;
			}
			pile[i] = m;
		}
	}

	public Machine depiler(){
		if(this.estVide()){
			System.out.println("Sorry, the pile if empty.");
			return null;
		}else{
			int i = pile.length;
			while(pile[i] == null){
				i--;
			}
			return pile[m];
		}	
	}

	public boolean estVide(){
		return (pile[0] == null);
	}

	public boolean estPleine(){
		return (pile[pile.length-1] != null);
	}

	// toString()
	public String toString(){
		String s ="";
		int i;
		for(i = 0; i<pile.length; i++){
			if(pile[i] != null){
				s = s + pile[i].toString() + ", ";	
			}else{
				return s;
			}	
		}
		return s;
	}
}