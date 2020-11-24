import java.util.ArrayList;

public class PoissonList extends ArrayList {

    ArrayList<Poisson> poissons;

    public PoissonList() {
        poissons = new ArrayList<Poisson>(); 
    }

    public PoissonList(PoissonList list) {
        poissons = new ArrayList<Poisson>();
        for (Poisson poisson : list.poissons) {
            poissons.add(poisson.clone());
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
    
    public int rangPoissonProche(int index){
        int lePlusProche = index;
        double minDistance = Double.POSITIVE_INFINITY;
        Poisson poissonIndex = poissons.get(index);
        for (int i = 1; i < poissons.size(); i++){
            if(poissons.get(i) == poissonIndex){continue;}
            double distance = poissons.get(i).getPosition().distanceTo(poissonIndex.getPosition());
            if(distance < minDistance){
                lePlusProche = i;
                minDistance = distance;
            }
        }

        return lePlusProche;
    }

    public void bougerTousPoissons(){
        Point centre = new Point(250, 250);
        for (Poisson poisson : poissons) {
            int indexPlusProche = rangPoissonProche(poissons.indexOf(poisson));
            Poisson poissonPlusProche = poissons.get(indexPlusProche);
            if(poissonPlusProche instanceof Thon){
                poisson.move(poissonPlusProche.getPosition());
            }else{
                poisson.move(centre);
            }
            poisson.verifPosition();
        }
    }

    public PoissonList faireUnPas() throws PoissonInconnuException {
        bougerTousPoissons();
        PoissonList l2 = new PoissonList(this);
        for (Poisson poisson : poissons) {
            int indexPlusProche = rangPoissonProche(poissons.indexOf(poisson));
            Poisson poissonPlusProche = poissons.get(indexPlusProche);
            boolean voisin = (poisson.getPosition().distanceTo(poissonPlusProche.getPosition()) < 2);
            if(voisin){
                if(poisson instanceof Thon && poissonPlusProche instanceof Requin){continue;}
                else if(poisson instanceof Thon && poissonPlusProche instanceof Thon && indexOf(poisson) < indexPlusProche){
                    l2.poissons.add(new Thon());
                    l2.poissons.add(poisson);
                }else if(poisson instanceof Requin){
                    l2.poissons.add(poisson);
                }else{
                    throw new PoissonInconnuException();
                }
            }else{
                l2.poissons.add(poisson);
            }
            poisson.verifPosition();
        }
        return l2;
    }
}
