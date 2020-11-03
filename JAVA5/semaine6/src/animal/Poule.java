public class Poule extends Animal {
    protected static int cpt = 0;
    protected int id;
    
    public Poule(int x, int y){
        super(x, y, "Poule");
        id = ++cpt;
    }

    @Override
    public String toString() {
        return String.format("p%02d", id);
    }

    public void afficher(){
        System.out.println(this.toString() + ", x = " + x + ", y = " + y);
    }

    
}
