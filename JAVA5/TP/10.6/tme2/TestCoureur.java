public class TestCoureur{
	public static void main(String[] args){
	Coureur c1 = new Coureur();
	System.out.println(c1.toString());
	Coureur c2 = new Coureur();
	System.out.println(c2.toString());
	Coureur c3 = new Coureur();
	System.out.println(c3.toString());
	Coureur c4 = new Coureur();
	System.out.println(c4.toString());
	
	c1.setPossedeTemoin(true);
	c1.courir();
	c1.passeTemoin(c2);
	c2.courir();
	c2.passeTemoin(c3);
	c3.courir();
	c3.passeTemoin(c4);
	c4.courir();
	double tps_tot=c1.getTempsAu100()+c2.getTempsAu100()+c3.getTempsAu100()+c4.getTempsAu100();
	System.out.println(" le temps totale est de : "+tps_tot);
	}
	
}
	
