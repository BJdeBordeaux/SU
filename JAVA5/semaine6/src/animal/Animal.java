public abstract class Animal {
    protected int x, y;
    protected String type;
    protected String poire;
    protected String predateur;

    public Animal(int x, int y, String type) {
        this.x = x;
        this.y = y;
        this.type = type;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public String getType() {
        return type;
    }

    public void move(int i, int j){
        x += i;
        y += j;
    }

    public abstract void move(Animal a);

    // public void move(Animal a){
    //     System.out.println(a.getType() + " " + poire + " " + predateur);
    //     if(a.getType() == poire){
    //         move((int) Math.signum(getX() - a.getX()), (int) Math.signum(getY() - a.getY()));
    //     }else if(a.getType() == predateur){
    //         move((int) Math.signum(-getX() + a.getX()), (int) Math.signum(-getY() + a.getY()));
    //     }
    // }

    public String getPoire() {
        return poire;
    }

    public String getPredateur() {
        return predateur;
    }

    
}
