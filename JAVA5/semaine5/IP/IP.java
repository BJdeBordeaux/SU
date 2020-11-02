public class IP{
	private static int[] tab = {192, 168, 0, 0};

	private IP(){}

	public static String getAdresseIP(){
		if(tab[3] == 255){
			if(tab[2] < 255){
				tab[2]++;
				tab[3] = 0;
			}
		}else{
			tab[3]++;
		}

		return String.format("[192.168.%d.%d]", tab[2], tab[3]);
	}


}