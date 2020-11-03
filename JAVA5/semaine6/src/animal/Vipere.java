public class Vipere extends Animal {
    protected static int cpt = 0;
    protected int id;
    
    public Vipere(int x, int y){
        super(x, y, "Vipere");
        id = ++cpt;
    }

    @Override
    public String toString() {
        return String.format("v%02d", id);
    }

    public void afficher(){
        System.out.println(this.toString() + ", x = " + x + ", y = " + y);
    }
}
