public abstract class Poisson {
    protected Point position;

    public Poisson() {
        this.position = new Point();
    }

    public Poisson(int x, int y) {
        this.position = new Point(x, y);
    }

    public void verifPosition() {
        int x = position.getX();
        int y = position.getY();
        if(x > 499){
            position.setX(x%500);
        }
        if(y > 499){
            position.setY(y%500);
        }
    }

    public abstract void move(Point cible);
}
