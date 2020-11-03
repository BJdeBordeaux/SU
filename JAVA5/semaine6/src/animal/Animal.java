public abstract class Animal {
    protected int x, y;
    protected String type;

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

    // public abstract void move(Animal a);
}
