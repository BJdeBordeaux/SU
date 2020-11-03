public class Vehicule {
    protected static int numero = 0;
    protected double distance_parcouru;

    public Vehicule() {
        this.distance_parcouru = 0;
        numero++;
    }

    @Override
    public String toString() {
        return "Vehicule [distance parcouru=" + distance_parcouru + "]";
    }

    public void rouler(double distance){
        distance_parcouru += distance;
        System.out.println("Je roule " + distance + "km!");
    }

    public static int getNumero() {
        return numero;
    }

    public double getDistance_parcouru() {
        return distance_parcouru;
    }
}