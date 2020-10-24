public class NUplet{
	private int[] tab;

	public NUplet(int n){
		tab = new int[n];
	}

	public NUplet(int n, int x){
		this(n);
		for(int i = 0; i < n; i++){
			tab[i] = x;
		}
	}

	public NUplet(int a, int b, int c){
		this(3);
		tab[0] = a;
		tab[1] = b;
		tab[2] = c;
	}

	public NUplet(int[] t){
		// tab = t;
		tab = t.clone();
	}

	public String toString(){
		if(tab.length==0){return "()";}
		else{
			String s ="(";
			int i = 0;
			while(i<tab.length-1){
				s = s + tab[i] + ", ";
				i++;
			}
			s = s + tab[i] + ")";
			return s;
		}
	}

	public int somme(){
		if(tab.length==0){return 0;}
		int i,s = 0;
		for(i= 0; i < tab.length; i++){
			s += tab[i];
		}
		return s;
	}

	public int[] getTab(){
		// return tab;
		return tab.clone();
	}

	public boolean egal(NUplet u){
		if(u == this){return true;}
		if(u == null){return false;}
		if(this.tab.length != u.tab.length){return false;}
		for(int i = 0; i < tab.length; i++){
			if(tab[i] != u[i]){
				return false;
			}
		}
		return true;
	}
}