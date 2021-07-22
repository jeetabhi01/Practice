public class Point {
    private double x, y;
    public Point(){
        x = 0.0;
        y = 0.0;
    }

    public Point(double x, double y){
       setXY(x, y);
    }

    public double distanceFromOrigin(){
        return Math.sqrt(x * x + y * y);
    }

    public String toString(){
        return "(" + this.x + ", " + this.y + ")";
    }

    public void translate(double dx, double dy){
        setXY(x+dx, y+dy);
    }

    public double getX(){
        return  x;
    }

    public double getY(){
        return y;
    }

    public  void setXY(double x, double y){
        this.x = x;
        this.y = y;
    }
}
