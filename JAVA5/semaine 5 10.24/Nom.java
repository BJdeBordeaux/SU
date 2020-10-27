public class Nom{
    private static char voyelles[]  = {'a', 'o', 'e', 'u', 'i'};
    private static char consonnes[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j',
            'k', 'l', 'm', 'n', 'p', 'q', 'r',
            's', 't', 'v', 'w', 'x', 'y', 'z'};
    public static int rendAlea(int inf, int sup){
        return (int)(Math.random()*(sup - inf + 1)+inf);
    }

    public static boolean estPair(int n){
        return (n%2 == 0);
    }

    public static char rendConsonne(){
        return consonnes[rendAlea(0, 20)];
    }

    public static char rendVoyelle(){
        return consonnes[rendAlea(0, 4)];
    }

    public static String genereNom() {
        int longeur = rendAlea(3, 6);
        String s = "";
        while (longeur >= 2) {
            s += rendConsonne();
            s += rendVoyelle();
            longeur -= 2;
        }
        if (!estPair(longeur)) {
            s += rendConsonne();
        }
        return s;
    }
}