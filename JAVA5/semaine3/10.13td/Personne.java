public class Personne{
	private String nom;
	private Personne conjoint;



	public Personne(){
		this("pers");
		nom = nom + tirageLettre() + tirageLettre() + tirageLettre();
	}

	public Personne(String nom){
		this.nom = nom;
		this.conjoint = null;
	}

	private char tirageLettre(){
		char s = (char)((int)(Math.random()*26)+'A');
		System.out.print(s);
		return (char)((int)(Math.random()*26)+'A');
	}

	public String toString(){
		String s = "célibataire";
		if(conjoint != null){s = "marié(e)";}
		return nom + ", " + s;
	}

	public void epouser(Personne p){
		if(this.conjoint != null || p.conjoint != null){
			System.out.println("Ce mariage est impossible!");		
		}else{
			this.conjoint = p;
			p.conjoint = this;
			System.out.println("Mariage de " + this.nom + " , célibataire et de " + p.nom + " , célibataire.");
		}
	}

	public void divorce(){
		if(this.conjoint == null){
			System.out.println("Not able to divorce.");
		}else{
			System.out.println("Divorce de " + this.nom + ", marié(e) et de " + this.conjoint.nom + "marié(e)");
			this.conjoint.conjoint = null;
			this.conjoint = null;
		}
	}
}