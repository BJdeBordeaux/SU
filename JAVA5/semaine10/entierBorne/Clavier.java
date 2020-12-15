import java.io.* ;

/**
 *Cette classe implante des saisies au clavier par lecture d'une ligne.
 */
public class Clavier {

  private static final BufferedReader in = new BufferedReader (new InputStreamReader (System.in)) ;

  /**
   * Affiche le message et retourne un int lu au clavier.
   */
  public static int saisirEntier (String mess){
	  while(true){
		  try {return Integer.parseInt (saisirLigne ( mess)) ;}
		  catch (NumberFormatException e) {mess = "Recommencez : " ;}
	  }
  }

  /**
   * Affiche le message et retourne un double lu au clavier. <br>
   * Accepte une virgule comme separateur entre parties entiere et decimales.
   */
  public static double saisirDouble (String mess){
	  while(true){
		  try {
			  return Double.valueOf(saisirLigne ( mess).replace (',', '.')).doubleValue () ;
		  }
		  catch (NumberFormatException e) {mess = "Recommencez : " ;}
	  }
  }

  /**
   * Affiche le message et retourne une ligne lue au clavier.
   */
  public static String saisirLigne (String mess) {
	  System.out.println (mess) ;
	  try{return in.readLine () ;}
	  catch (IOException e){return null;}// provisoire !!
  }

  /**
   * Fait dormir le processus un certain nombre de millisecondes.
   */        
   public static void dormir (int n) {
		try{Thread.sleep(n) ;}
		catch (InterruptedException e) {}
  }
   
} // Clavier