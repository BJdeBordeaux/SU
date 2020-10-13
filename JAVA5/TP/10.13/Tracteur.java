public class Tracteur{

	private Roue ra, rb, rc, rd;
	private Cabine ca;

	public Tracteur(Roue ra, Roue rb, Roue rc, Roue rd, Cabine ca){
		this.ra = ra;
		this.rb = rb;
		this.rc = rc;
		this.rd = rd;
		this.ca = ca;
	}

	public String toString(){
		String s0 = "This is a tractor.\n";
		String s1 = ra.toString()+"\n"+rb.toString()+"\n"+rc.toString()+"\n"+rd.toString()+"\n";
		String s2 = ca.toString();
		return s0 + s1 + s2;
	}

	public void peindre(String c){
		ca.setCouleur(c);
	}

	public Tracteur clone(){
		Roue raa = this.ra.clone();
		Roue rbb = this.rb.clone();
		Roue rcc = this.rc.clone();
		Roue rdd = this.rd.clone();
		Cabine caa = this.ca.clone();
		return new Tracteur(raa, rbb, rcc, rdd, caa);
	}
}