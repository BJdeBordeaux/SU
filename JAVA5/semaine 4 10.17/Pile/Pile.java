public class Pile{
	// attributs
	private Machine[] pile;

	public Pile(){
		pile = new Machine[20]; 
		for(int i = 0; i<pile.length; i++){
			pile[i] = null;
		}
	}

	public void empiler(Machine m){
		if(this.estPleine()){
			System.out.println("Sorry, the pile if full.");
		}else{
			int i;
			for(i = pile.length-1; i > 0; i--){
				pile[i] = pile[i-1];
			}
			pile[0] = m;
		}
	}

	public Machine depiler(){
		if(this.estVide()){
			System.out.println("Sorry, the pile if empty.");
			return null;
		}else{
			Machine m = pile[0];
			int i;
			for(i = 1; i < pile.length; i++){
				pile[i-1] = pile[i];
			}
			return m;
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