import java.util.ArrayList;

public class PoissonList2 extends ArrayList<Poisson> {

    public PoissonList2() {
    }

    public PoissonList2(PoissonList2 list) {
        for (Poisson poisson : list) {
            add(poisson.clone());
        }
        
    }

    public int nbThon() {
        int cpt = 0;
        for (Poisson poisson : this) {
            if(poisson instanceof Thon){
                cpt += 1;
            }
        }
        return cpt;
    }
    
    public int rangPoissonProche(int index){
        int lePlusProche = index;
        double minDistance = Double.POSITIVE_INFINITY;
        Poisson poissonIndex = get(index);
        for (int i = 1; i < size(); i++){
            if(get(i) == poissonIndex){continue;}
            double distance = get(i).getPosition().distanceTo(poissonIndex.getPosition());
            if(distance < minDistance){
                lePlusProche = i;
                minDistance = distance;
            }
        }

        return lePlusProche;
    }

    public void bougerTousPoissons(){
        Point centre = new Point(250, 250);
        for (Poisson poisson : this) {
            int indexPlusProche = rangPoissonProche(indexOf(poisson));
            Poisson poissonPlusProche = get(indexPlusProche);
            if(poissonPlusProche instanceof Thon){
                poisson.move(poissonPlusProche.getPosition());
            }else{
                poisson.move(centre);
            }
            poisson.verifPosition();
        }
    }

    public PoissonList2 faireUnPas() throws PoissonInconnuException {
        bougerTousPoissons();
        PoissonList2 l2 = new PoissonList2();
        for (Poisson poisson : this) {
            int indexPlusProche = rangPoissonProche(indexOf(poisson));
            Poisson poissonPlusProche = get(indexPlusProche);
            boolean voisin = (poisson.getPosition().distanceTo(poissonPlusProche.getPosition()) < 2);
            if(voisin){
                if(poisson instanceof Thon && poissonPlusProche instanceof Requin){continue;}
                else if(poisson instanceof Thon && poissonPlusProche instanceof Thon && indexOf(poisson) < indexPlusProche){
                    l2.add(new Thon());
                    l2.add(poisson);
                }else if(poisson instanceof Requin){
                    l2.add(poisson);
                }else{
                    throw new PoissonInconnuException();
                }
            }else{
                l2.add(poisson);
            }
            poisson.verifPosition();
        }
        return l2;
    }
}
