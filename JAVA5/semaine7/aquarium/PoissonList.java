import java.util.ArrayList;

public class PoissonList extends ArrayList {

    ArrayList<Poisson> poissons;

    public PoissonList() {
        poissons = new ArrayList<Poisson>(); 
    }

    public PoissonList(PoissonList list) {
        for (Poisson poisson : list) {
            add(poisson.copy());
        }
        
    }

    public int nbThon() {
        int cpt = 0;
        for (Poisson poisson : poissons) {
            if(poisson instanceof Thon){
                cpt += 1;
            }
        }
        return cpt;
    }
    
    
}
