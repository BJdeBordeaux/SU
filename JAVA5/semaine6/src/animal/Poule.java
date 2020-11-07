public class Poule extends Animal {
    protected static int cpt = 0;
    protected int id;
    protected final String poire = "Vipere";
    protected final String predateur = "Renard";
    
    public Poule(int x, int y){
        super(x, y, "Poule");
        id = ++cpt;
        // poire = "Vipere";
        // predateur = "Renard";
    }

    @Override
    public String toString() {
        return String.format("p%02d", id);
    }

    public void afficher(){
        System.out.println(this.toString() + ", x = " + x + ", y = " + y);
    }

    public void move(Animal a){
        if(a.getType() == "Vipere"){
            move((int) Math.signum(getX() - a.getX()), (int) Math.signum(getY() - a.getY()));
        }else if(a.getType() == "Renard"){
            move((int) Math.signum(-getX() + a.getX()), (int) Math.signum(-getY() + a.getY()));
        }
    }

    public String getPoire() {
        return poire;
    }

    public String getPredateur() {
        return predateur;
    }

}
