public class Faune {
    public static final int TAILLE = 15;
    public static final int NBANIMAL = 21;
    protected Animal[] tab;
    protected int nb_a = 0;

    public Faune() {
        tab = new Animal[NBANIMAL];
        for(int i = 0; i < NBANIMAL/3; i++){
            tab[i] = new Vipere((int)(Math.random()*TAILLE), (int)(Math.random()*TAILLE));
            tab[i+NBANIMAL/3] = new Renard((int)(Math.random()*TAILLE), (int)(Math.random()*TAILLE));
            tab[i+2*NBANIMAL/3] = new Poule((int)(Math.random()*TAILLE), (int)(Math.random()*TAILLE));
            nb_a += 3;
        }
    }

    public String terrain(){
        String[][] terr = new String[TAILLE][TAILLE];
        for(int i = 0; i < terr.length; i++){
            for(int j = 0; j < terr[i].length; j++){
                terr[i][j] = " . ";
            }
        }

        Animal a = tab[0];
        nb_a = 0;
        while(a != null && nb_a < NBANIMAL){
            terr[a.getX()][a.getY()] = a.toString();
            a = tab[nb_a++];
        }

        String res = "";
        
        String head ="";
        for(int i = 0; i < TAILLE*3 + 2; i++){
            head = head + "-";
        }
        res = res + head + "\n";

        for(int i = 0; i < TAILLE; i++){
            res = res + "|";
            for(int j = 0; j < TAILLE; j++){
                res = res + terr[i][j];
            }
            res = res + "|\n";
        }
        res = res + head +"\n";

        return res;
    }

    public double distance(double xa, double ya, double xb, double yb){
        double dx = xa - xb;
        double dy = ya - yb;
        return (Math.sqrt(dx*dx + dy*dy));
    }

    public int getIndiceAnimalLePlusProche(Animal requete){
        Double dist_min = Double.POSITIVE_INFINITY;
        int index = -1;
        int xa, ya;
        int xb = requete.getX();
        int yb = requete.getY();
        double d;
        for(int i = 0; i < tab.length; i++){
            xa = tab[i].getX();
            ya = tab[i].getY();
            if(tab[i] == requete){continue;}
            else if(tab[i] == null){continue;}
            else if((d = distance(xa, ya, xb, yb)) < dist_min){
                dist_min = d;
                index = i;
            }

        }
        return index;
    }

    public void etatDeLaFaune(){
        for(int i = 0; i < nb_a; i++){
            System.out.println("Indice le plus proche : " + getIndiceAnimalLePlusProche(tab[i])
                + " pour " + tab[i].toString());
        }
    }

    public Animal[] getTab() {
        return tab;
    }

}
