public class Point {  
    public int x,y;  
    public Point(int x, int y){ this.x=x;this.y=y; }  
    public Point() {      /* initialise x et y entre 0 et 499 */      
      this((int)(Math.random() * 500),(int)(Math.random() * 500));  
    }  
    public String toString() { return "("+x+","+y+") "; }  
    public double distanceTo(Point p) {      
      int dx = p.x-x;      
      int dy = p.y-y;      
      return Math.sqrt(dx*dx+dy*dy);  
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    
  }
/*
LI Junji 28610187
* Bon c'est pas moi qui ecrit cette classe apparament XD
*/