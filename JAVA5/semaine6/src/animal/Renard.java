public class Renard extends Animal {
    protected static int cpt = 0;
    protected int id;
    protected final String poire = "Poule";
    protected final String predateur = "Vipere";
    
    public Renard(int x, int y){
        super(x, y, "Renard");
        id = ++cpt;
    }

    @Override
    public String toString() {
        return String.format("r%02d", id);
    }

    public void afficher(){
        System.out.println(this.toString() + ", x = " + x + ", y = " + y);
    }

    public void move(Animal a){
        if(a.getType() == "Poule"){
            move((int) Math.signum(getX() - a.getX()), (int) Math.signum(getY() - a.getY()));
        }else if(a.getType() == "Vipere"){
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
