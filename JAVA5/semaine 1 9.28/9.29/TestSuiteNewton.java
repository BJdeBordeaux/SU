public class TestSuiteNewton{
	public static void main(String[] args){
		SuiteNewton s1 = new SuiteNewton(9, 0.000001);
		s1.racine();
		SuiteNewton s2 = new SuiteNewton(2, 0.0001);
		s2.racine();
		SuiteNewton s3 = new SuiteNewton(3, 0.0001);
		s3.racine();
		SuiteNewton s4 = new SuiteNewton(4, 0.0001);
		s4.racine();
		SuiteNewton s5 = new SuiteNewton(5, 0.000001);
		s5.racine();
	}
}