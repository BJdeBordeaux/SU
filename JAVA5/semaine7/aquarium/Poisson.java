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
        if (x < 0){
            position.setX(-(-x % 500) + 500);
        }else if (x > 499) {
            position.setX(x % 500);
        }
        if (y < 0){
            position.setX(-(-y % 500) + 500);
        } else if (y > 499) {
            position.setY(y % 500);
        }
    }

    

    public abstract void move(Point cible);

    public abstract Poisson clone();

    public Point getPosition() {
        return position;
    }

    public void setPosition(Point position) {
        this.position = position;
    }
}
