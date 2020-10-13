public class SuiteNewton{
	private double x;
	private double eps;
	private double u;

	public SuiteNewton(double x0, double e){
		x = x0;
		u = x/2;
		eps = e;

	}

	public double getX(){
		return x;
	}

	public double getEps(){
		return eps;
	}

	public double next(){
		u = (u + x/u)/2;
		System.out.println("next = " + u);
		return u;
	}
}