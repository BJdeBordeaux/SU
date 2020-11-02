public class TestPersonne{
	public static void main(String[] args){
		Personne pa = new Personne();
		Personne pb = new Personne();
		Personne pc = new Personne();
		System.out.println(pa.toString());
		System.out.println(pb.toString());
		System.out.println(pc.toString());
		pa.epouser(pb);
		pb.epouser(pc);
		System.out.println(pa.toString());
		System.out.println(pb.toString());
		System.out.println(pc.toString());
		pb.divorce();
		System.out.println(pa.toString());
		System.out.println(pb.toString());
		System.out.println(pc.toString());
	}
}