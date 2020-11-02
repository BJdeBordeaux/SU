public class TestVector{
	public static void main(String[] args){
		Vector va = new Vector();
		Vector vb = new Vector(1, 2, 3);
		System.out.println(va.toString() + "; " + vb.toString());
		Vector vc = va.sommeVector(vb);
		Vector vd = Vector.somme(va, vb);
		System.out.println(vc.toString() + "; " + vd.toString());
	}
}