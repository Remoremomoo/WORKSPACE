import java.util.Scanner;

public class Shapes {
    float length, width, area, sides;
    double radius, areaC;

    Shapes(float side){
        this.sides = side;
        this.area = side * side;
        System.out.println("Shape: Square");
        System.out.println("Area: " + this.area);
    }
    Shapes(float l, float w){
        this.length = l;
        this.width = w;
        this.area = l * w;
        System.out.println("Shape: Rectangle");
        System.out.println("Area: " + this.area);
    }
    Shapes(double rad){
        this.radius = rad;
        this.areaC = rad * rad * 3.14;
        System.out.println("Shape: Circle");
        System.out.println("Area: " + this.areaC);
    }
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        float len, wid;
        double r;
        System.out.println("Enter Length (0 if none): ");
        len = sc.nextFloat();
        sc.nextLine();
        System.out.println("Enter Width (0 if none): ");
        wid = sc.nextFloat();
        if(len == 0 && wid == 0){
            System.out.println("Enter Radius: ");
            r = sc.nextDouble();
            sc.nextLine();
            Shapes shape = new Shapes(r);
        }
        else if(wid == 0){
            Shapes shape = new Shapes(len);
        }
        else{
            Shapes shape = new Shapes(len, wid);
        }
        sc.close();
    }
}
