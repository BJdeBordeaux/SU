public class Alphabet{
	public static void main(String[] args){
		char c;
		int i;
		for(c = '0', i = '0'; i <= '9' && c <= '9' ; i++, c++){
			System.out.println("char, ascii: " + c +", "+ i);
		}

		for(c = 'a', i = 'a'; c <= 'z' && i <= 'z'; c++, i++){
			System.out.println("char, ascii: " + c +", "+ i);
		}

		c = 'A';
		i = 'A';
		while( c <= 'Z' && i <= 'Z'){
			System.out.println("char, ascii: " + c +", "+ i);
			c++;
			i++;
		}
	}
}