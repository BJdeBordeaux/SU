public class TableauInt{
	private int[] tab;

	public TableauInt(){
		int len = 10;
		tab = new int[len];
		for(int i = 0; i < len; i++){
			tab[i] = (int)(Math.random()*101);
		}
	}

	public TableauInt(int n){
		int len = 10;
		tab = new int[len];
		for(int i = 0; i < len; i++){
			tab[i] = n + i;
		}
	}

	public String toString(){
		String s ="[";
		int i;
		for(i = 0; i<tab.length-1; i++){
			s = s + tab[i] + ", ";
		}
		s = s + tab[i] + "]";
		return s;
	}

	public int rangMax(){
		int rang = 0;
		int max = tab[0];
		for(int i = 0; i<tab.length; i++){
			if(tab[i] > max){
				max = tab[i];
				rang = i;
			}
		}
		return rang;
	}

	public int somme(){
		int s = 0;
		for(int i = 0; i<tab.length; i++){
			s += tab[i];
		}
		return s;
	}

	public boolean egal(TableauInt t){
		for(int i = 0; i < tab.length; i++){
			if(tab[i] !=  t.tab[i]){
				return false;
			}
		}
		return true;
	}
}