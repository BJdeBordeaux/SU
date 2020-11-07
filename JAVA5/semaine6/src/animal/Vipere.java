public class Vipere extends Animal {
    protected static int cpt = 0;
    protected int id;
    protected final String poire = "Renard";
    protected final String predateur = "Poule";
    
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

    public void move(Animal a){
        if(a.getType() == "Renard"){
            move((int) Math.signum(getX() - a.getX()), (int) Math.signum(getY() - a.getY()));
        }else if(a.getType() == "Poule"){
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
