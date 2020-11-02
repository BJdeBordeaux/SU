public class Coureur{
	private int numDossard;
	private double tempsAu100;
	private boolean possedeTemoin;
	
	public Coureur(int num)
	{
		numDossard = num;
		tempsAu100 = Math.random()*4+12;
		possedeTemoin = false;
	}
	 
	public Coureur()
	{
		this((int)(Math.random()*1000+1));
	}
	
	public int getNumDossard()
	{
		return numDossard;
	}
	public double getTempsAu100()
	{
		return tempsAu100;
	}
	
	public boolean getPossedeTemoin()
	{
		return possedeTemoin;
	}
	
	
	public void setPossedeTemoin(boolean b)
	{
		possedeTemoin = b;
	}
	
	public String toString()
	{
		return "courreur : "+numDossard+" tempsAu100 : "+tempsAu100+"s au 100 mètre possedeTemoin : "+possedeTemoin; 
	}

	public void passeTemoin (Coureur c)
	{
		System.out.println("moi, courreur "+numDossard+", je passe le temoin au coureur "+c.numDossard);
		this.possedeTemoin= false;
		c.possedeTemoin = true;
	}
	
	public void courir()
	{
		System.out.println("je suis le courreur "+numDossard+" et je cours.");
		
	}
	
}
	
