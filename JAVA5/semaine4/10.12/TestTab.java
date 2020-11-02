public class TestTab{
	public static void main(String[] args){
		double[] a = new double[10];
		for(int i = 0; i<10; i++){
			a[i] = Math.random();
		}
		for(int i = 0; i<10; i++){
			System.out.println(a[i]);
		}

		Point[] pts = new Point[10];
		for(int i = 0; i<10; i++){
			pts[i] = new Point();
		}

		for(int i = 0; i<10; i++){
			System.out.println(pts[i].toString());
		}

		int[] ta = {1, 2, 3};
		int[] tb = {1, 2, 3};
		int[] tc = ta;
		System.out.println(ta == tb);
		System.out.println(ta == tc);
		System.out.println(tb == tc);
	}
}