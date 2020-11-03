public class TestVehicule {
    public static void main(String[] args) {
        Velo vl = new Velo(15, 3);
        System.out.println(vl.toString());
        vl.transporter("Angers", "Paris");
        Voiture vt = new Voiture(50, 50, 4);
        vt.transporter(3, 150);
        Camion c = new Camion(100, 200, 300);
        c.transporter("Radio", 50);
    }
}
