import java.util.Scanner;

public class PointClient {
    public static void main(String[] args){
        
        Scanner console = new Scanner(System.in);
        double dx, dy;
        dx = console.nextDouble();
        dy = console.nextDouble();
        Point y = new Point(dx,dy);
        System.out.println(y);
        System.out.printf("Distance from origin is: %.2f\n" , y.distanceFromOrigin());

        Point x = new Point(10.57, 11);
        System.out.println(x);
        x.translate(1.23, 2.24);
        System.out.println("Translating x by (1.23, 2.24): "  + x);
        console.close();
    }
}
