public class Thon extends Poisson{
    public Thon() {
        super();
    }

    public Thon(int x, int y) {
        super(x, y);
    }

    @Override
    public String toString() {
        return "Thon ["+ super.position.getX() + 
        ", " + super.position.getY() +"]";
    }
    
    public void move(Point cible) {
        if(this.position.distanceTo(cible) >= 60){
            position.setX((position.getX() + (int)(Math.random() * 31 -15));
            position.setY((position.getY() + (int)(Math.random() * 31 -15));
        }else{
            position.setX((position.getX() + cible.getX())/2);
            position.setY((position.getY() + cible.getY())/2);
        }
        verifPosition();
    }

    @Override
    public Thon clone(){
        return new Thon(position.getX(), position.getY());
    }
}
