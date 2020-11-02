public class TestVecteur{
	public static void main(String[] args){
		/*
		ex1
		int s = 0;
		for(int i = 2; i <= 60; i++){
			if(i%2 == 0) s+=i;
		}
		System.out.println("i = " + s + " \n");*/

		/*
		ex2
		double a = Math.random();
		double b = Math.random()*10;
		double c = Math.cos(Math.PI);
		System.out.println("a, b, c = " + a + ", " + b + ", " + c);*/

		/*
		ex3
		int i = 3;
		if(2<i<10) System.out.println("1");
		if(i)  System.out.println("2");
		if((i<5) && i == 2 )  System.out.println("3");
		if( i < 5 || i == 2 )  System.out.println("4");*/

		/*
		ex4
		String s = "affichage";
		// char s2[] = "bien";
		char e = s.charAt(s.length()-1);
		if(e == 'e'){
			System.out.println("mot feminin: "+s);
		}else{
			System.out.println("mot masculin: "+s);
		}
		*/
		
		// System.out.printf("[%.2f]",Math.PI);

		Vecteur v = new Vecteur(1., 2.);
		Vecteur v2 = new Vecteur();
		System.out.println(v.toString());
		System.out.println(v2.toString());
		Vecteur v3 = v.ProduitScalaire(2);
		System.out.println(v3.toString());
	}
}