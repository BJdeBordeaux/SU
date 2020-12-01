
public class TestTrain {
    public static void main(String[] args) {
        Motrice m = new Motrice("Alstom");
        Train t = new Train(m);
        for (int i = 0; i < 5; i++) {
            t.ajouter(new WVoyageur("Hongxing"));
            t.ajouter(new WMarchandise("SNCF"));
        }
        System.out.println(t);
        System.out.println("Nombre de place = " + t.nbPlace() + "\n");
        System.out.println("Poids max = " + t.poids() + "\n");
    }
}
