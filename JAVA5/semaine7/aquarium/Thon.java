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
        if(posistion.distanceTo(cible) >= 60){
            position.setX((posistion.getX() + (int)(Math.random() * 31 -15));
            position.setY((posistion.getY() + (int)(Math.random() * 31 -15));
        }else{
            position.setX((posistion.getX() + cible.getX())/2);
            position.setY((posistion.getY() + cible.getY())/2);
        }
        verifPosition();
    }

    
}
