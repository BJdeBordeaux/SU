public class SuiteNewton{
	private double x;
	private double eps;
	private double u;
	private double u_d;

	public SuiteNewton(double x0, double e){
		x = x0;
		u_d = x0;
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
		u_d = u;
		u = (u + x/u)/2;
		System.out.println("next = " + u);
		return u;
	}

	public double racine(){
		while((Math.abs(u_d-u)>eps)){
			this.next();
		}
		System.out.println("racine de " + x + "= " + u);
		return u;
	}
}