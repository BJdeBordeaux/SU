public class Requin extends Poisson{

    public Requin() {
        super();
    }

    public Requin(int x, int y) {
        super(x, y);
    }

    @Override
    public String toString() {
        return "Requin ["+ super.position.getX() + 
        ", " + super.position.getY() +"]";
    }
    
    public void move(Point cible) {
        position.setX((posistion.getX() + cible.getX())/2);
        position.setY((posistion.getY() + cible.getY())/2);
        verifPosition();
    }

    @Override
    public Requin clone(){
        return new Requin(position.getX(), position.getY());
    }
}
