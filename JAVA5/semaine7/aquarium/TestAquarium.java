/*
LI Junji 28610187
*/
public class TestAquarium {
    public static void main(String[] args) throws PoissonInconnuException {
        try {
            int nbThon = Integer.parseInt(args[0]);
            int nbRequin = Integer.parseInt(args[1]);
        } catch (Exception e) {
            System.err.println("Donnee non entiere");
            return;
        }
        int nbThon = Integer.parseInt(args[0]);
        int nbRequin = Integer.parseInt(args[1]);
        if(nbThon < 0 || nbRequin < 0){
            System.err.println("The arguments must be greater than 0.");
            return;
        }
        Aquarium aquarium = new Aquarium(nbThon, nbRequin);
        System.out.println("La liste avant faireUnPas()");
        System.out.println(aquarium.toString());
        aquarium.poissonList.faireUnPas();
        System.out.println("La liste apres faireUnPas()");
        System.out.println(aquarium.toString());
    }
}
