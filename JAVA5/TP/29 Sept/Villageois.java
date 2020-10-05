public class Villageois{
	private String nom;
	private double poids;
	private boolean malade;

	public Villageois(String nomVillageois){
		nom = nomVillageois;
		poids = Math.random()*100+50;
		malade = (Math.random()<0.2);
	}

	public String getNom(){
		return nom;
	}

	public double getPoids(){
		return poids;
	}

	public boolean getMalade(){
		return malade;
	}

	public String toString(){
		String s = "Villageois: " + nom + ", poids :" + (int) poids + " kg, malade : ";
		if(malade){s+= "oui.";}
		else{s+= "non.";}
		return s;
	}

	public double poidsSouleve(){
		if(malade){return poids/4;}
		else{return poids/3;}
	}
}