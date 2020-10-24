public class TrianglePascal{

	// attributs
	private int[][] c;

	// constructeur avec paramètres
	public TrianglePascal(int n){
		c = new int[n][];
		for(int i = 0; i<n; i++){
			c[i] = new int[i+1];
		}
	}

	public void remplirTriangle(){
		int i, j;
		for(i = 0; i < c.length; i++){
			for(j = 0; j < c[i].length; j++){
				if((j == 0) || (j == i)){
					c[i][j] = 1;	
				}else{
					c[i][j] = c[i-1][j-1] + c[i-1][j]; 
				}
			}
		} 
	}

	// toString()
	public String toString(){
		String s = "";
		int i, j;
		for(i = 0; i < c.length; i++){
			for(j = 0; j< c[i].length; j++){
					s = s + c[i][j] + " ";
				}
			s = s + "\n";
			}
		return s;
	}	
}