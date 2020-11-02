public class TestNote{
	public static void main(String[] args){
		Double a = 1.;
		Double b = 1.;
		System.out.println(a==b);//false
		double c = Double.valueOf("2.2");
		System.out.println("Max, Inf, valueof'2.2' :"
			+ Double.MAX_VALUE+","
			+ Double.POSITIVE_INFINITY+","
			+c+".");
	}
}