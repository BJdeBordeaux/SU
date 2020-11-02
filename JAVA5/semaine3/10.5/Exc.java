public class Exc{
	public static void main(String[] args){
		double[] tab = {0,1,2,3};
		try{
			for(int i = 0; i < 5; i++){
			System.out.println("I'm "+ tab[i] + ".");
			}
		}catch(ArrayIndexOutOfBoundsException e){
			System.out.println("oh exp");
		}finally{
			System.out.println("end!");
		}
	}
}