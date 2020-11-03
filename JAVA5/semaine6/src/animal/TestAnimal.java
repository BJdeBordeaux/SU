public class TestAnimal {
    public static void main(String[] args) {
        Poule pa = new Poule((int)(Math.random()*6), (int)(Math.random()*6));
        Poule pb = new Poule((int)(Math.random()*6), (int)(Math.random()*6));
        Poule pc = new Poule((int)(Math.random()*6), (int)(Math.random()*6));
        Vipere va = new Vipere((int)(Math.random()*6), (int)(Math.random()*6));
        Vipere vb = new Vipere((int)(Math.random()*6), (int)(Math.random()*6));
        Vipere vc = new Vipere((int)(Math.random()*6), (int)(Math.random()*6));
        Renard ra = new Renard((int)(Math.random()*6), (int)(Math.random()*6));
        Renard rb = new Renard((int)(Math.random()*6), (int)(Math.random()*6));
        Renard rc = new Renard((int)(Math.random()*6), (int)(Math.random()*6));
        pa.afficher();
        pb.afficher();
        pc.afficher();
        ra.afficher();
        rb.afficher();
        rc.afficher();
        va.afficher();
        vb.afficher();
        vc.afficher();
    }
}
