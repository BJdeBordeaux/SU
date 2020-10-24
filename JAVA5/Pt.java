public class Pt{

	// attributs
	private Type1 Att1;

	// constructeur sans paramètre
	public Pt(){
		
	}

	// constructeur avec paramètres
	public Pt(int n){
		
	}

	// toString()
	public String toString(){
		String s = ;
		
		return s;
	}

	// get() méthodes
	public int getAtt1(){
		return ;
	}

	// modification méthode
	private void ModificationAtt1(){

	}

	// utilisation d'attribut
	public int somme(){

		return ;
	}

	// egal
	public boolean equals(Pt p){
		System.out.println("m0");
		if(p == this){return true;}
		if(p == null){return false;}
		if(p.getClass() != this.getClass())
		// if(!(p instanceof Poin t))
			{System.out.println("m1");return false;}
		Point o = (Point) p;
		if(o.getX() != this.getX()){System.out.println("m2");return false;}
		if(o.getY() != this.getY()){System.out.println("m3");return false;}
		return true;
	}
}

	/*
	*for expr
	
	for(int i = 0; i<tab.length; i++){
			
		}

	*interval int [a, b]
	(int)(Math.random()*(min-max+1) + min)
	*/