public class Aquarium {
    PoissonList poissonList;

    public Aquarium(int nbThon, int nbRequin) {
        poissonList = new PoissonList();
        int i;
        for (i = 0; i < nbThon; i++) {
            poissonList.add(new Thon());
        }
        for (i = 0; i < nbRequin; i++) {
            poissonList.add(new Requin());
        }
    }

    @Override
    public String toString(){
        String string = "[";
        for (Poisson poisson : poissonList) {
            string += poisson.toString() + " , ";
        }
        string += "]";
        return string;
    }
}
