package point;

public class Point {

    private int x, y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public Point () {
        x = 0;
        y = 0;
    }

    public Point(Point p){
        x = p.x;
        y = p.y;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() == obj.getClass()){
            Point p = (Point) obj;
            return (this.x == p.x) && (this.y == p.y);
        }
        return false;
    }

    
}