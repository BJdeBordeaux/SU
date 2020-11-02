public class Lapin{
	private double posx;
	private double posy;
	private int nbEnfants;

	public Lapin(double posx, double posy){
		this.posx = posx;
		this.posy = posy;
	}

	public Lapin(){
		this((Math.random()*20-10),(Math.random()*20-10));
	}

	public String toString(){
		return "Lapin posx, posy, nbEnfants : " + posx + ", "+ posy + ", "+ nbEnfants + ".";
	}

	public void deplacer(double x, double y){
		this.posx += posx;
		this.posy += posy;
	}

	public Lapin reproduire(Lapin l){
		if ((this.posx == l.posx) && (this.posy == l.posy)){
			this.nbEnfants ++;
			l.nbEnfants++;
			return new Lapin(this.posx, this.posy);
		}else{
			return null;
		}
	}

	public boolean estParents(){
		return this.nbEnfants>0;
	}
}