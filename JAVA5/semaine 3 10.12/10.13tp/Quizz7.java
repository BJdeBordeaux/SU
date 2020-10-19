public class Quizz7{
	public static void main(String[] args){
		A a = new A();
		A a2 = a;
		A a3 = new A();
		A a4 = null;

		//QZ 7.1-3 : 0 constructeur. 2 objets. 3 références.
		//QZ 7.4 : a3 = null; l'instance référencée par a3 sera déréférencée, donc détruit.
		// a2 = null; a2 référence à null mais l'instance référencée par a1 (et avant par a2) existe car elle est référencée par a1
		// a1 = null; l'instance référencée par a1 sera déréférencée, donc détruit.

	}	
}