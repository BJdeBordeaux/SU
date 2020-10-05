public class Solu{
	public static void main(String[] args){
		SuiteNewton s = new SuiteNewton(7., .000001);
		int i;
		for(i = 0; i < 99; i++){
			s.next();
		}
	}
}