public class Faune {
    public static final int TAILLE = 15;
    public static final int NBANIMAL = 21;
    protected Animal[] tab;

    public Faune() {
        tab = new Animal[NBANIMAL];
        for(int i = 0; i < NBANIMAL/3; i++){
            tab[i] = new Vipere((int)(Math.random()*TAILLE), (int)(Math.random()*TAILLE));
            tab[i+NBANIMAL/3] = new Renard((int)(Math.random()*TAILLE), (int)(Math.random()*TAILLE));
            tab[i+2*NBANIMAL/3] = new Poule((int)(Math.random()*TAILLE), (int)(Math.random()*TAILLE));
            // nb_a += 3;
        }
    }

    public String terrain(){
        String[][] terr = new String[TAILLE][TAILLE];
        for(int i = 0; i < terr.length; i++){
            for(int j = 0; j < terr[i].length; j++){
                terr[i][j] = " . ";
            }
        }

        
        
        for(Animal a: tab){
            if(a != null){
                terr[a.getX()][a.getY()] = a.toString();
            }
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
        int xb = requete.getX();
        int yb = requete.getY();
        double d;
        for(int i = 0; i < tab.length; i++){
            if(tab[i] == requete){continue;}
            else if(tab[i] == null){continue;}
            else if((d = distance(tab[i].getX(), tab[i].getY(), xb, yb)) < dist_min){
                dist_min = d;
                index = i;
            }

        }
        return index;
    }

    public void etatDeLaFaune(){
        for(int i = 0; i < tab.length; i++){
            if(tab[i] != null){
                System.out.println("Indice le plus proche : " + getIndiceAnimalLePlusProche(tab[i])
                + " pour " + tab[i].toString());
            }
        }
    }



    public Animal[] getTab() {
        return tab;
    }

    public void update(){
        for(Animal a : tab){
            if(a == null){
                continue;
            }
            Animal proche = tab[getIndiceAnimalLePlusProche(a)];
            // System.out.println(a + " a pour voisin le plus proche : " + proche);
            a.move(proche);
            // int moveX = 0, moveY = 0;
            if(a.getX() >= TAILLE){
                a.move(-1,0);
                // moveX = 1;
            }else if(a.getX() < 0){
                a.move(1,0);
                // moveX = -1;
            }
            if(a.getY() >= TAILLE){
                // moveY = 1;
                a.move(0,-1);
            }else if(a.getY() < 0){
                // moveY = -1;
                a.move(0,1);
            }
            // a.move(-TAILLE*moveX, -TAILLE*moveY);
        }


        int[] mondeX = new int[tab.length];
        int[] mondeY = new int[tab.length];
        for(int i = 0; i < tab.length; i++){
            if(tab[i] == null){continue;}
            mondeX[i] = tab[i].getX();
            mondeY[i] = tab[i].getY();
            for(int j = 0; j < i; j++){
                if(tab[j] == null){continue;}
                if(mondeX[i] == mondeX[j] && mondeY[i] == mondeY[j]){
                    if(tab[i].getPoire() == tab[j].getType()){
                        System.out.println(tab[i].toString() + " mange " + tab[j].toString());
                        tab[j] = null;
                    }else if(tab[i].getPredateur() == tab[j].getType()){
                        System.out.println(tab[j].toString() + " mange " + tab[i].toString());
                        tab[i] = null;
                        break;
                    }
                }
            }
        }
    }
}
