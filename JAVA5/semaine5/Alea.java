public class Alea{

	private Alea(){};
	public static char lettre(){
		return (char)((int)(Math.random()*26)+'a');
	}

	public static String chaine(){
		String s = "";
		for(int i = 0; i < 10; i++){
			s += lettre();
		}
		return s;
	}
}