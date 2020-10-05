import java.util.ArrayList;
public class TestDet{
	public static void main(String[] args){
		// Det t = new Det(5);
		// Det t2 = t;
		// System.out.println(t2.toString());
		// t = null;

		ArrayList<Det> t3 = new ArrayList<Det>();
		for(int i = 0; i < 5; i++){
			t3.add(new Det(i));
			System.out.println(t3.get(i));
		}
		t3.remove(0);
		System.out.println(t3.get(0));
		System.out.println(t3.size());
	}
}