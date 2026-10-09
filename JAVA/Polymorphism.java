class Calculator{
    int multiply(int x, int y){
        return x * y;
    }
    int multiply(int x, int y, int z){
        return x * y * z;
    }
    double multiply(double x, double y){
        return x * y;
    }
}
class Vehicle{
    void move(String name){
        System.out.println(name + " is moving");
    }
}
class Car extends Vehicle{
    String name;
    @Override
    void move(String name){
        System.out.println(name + " is moving on the road.");
    }
}
class Motorcycle extends Vehicle{
    String name;
    @Override
    void move(String name){
        System.out.println(name + " is moving through traffic.");
    }
}
class Bus extends Vehicle{
    String name;
    @Override
    void move(String name){
        System.out.println(name + " is transporting passengers.");
    }
}
abstract class Student{
    protected String name;

    Student(String name){
        this.name = name;
    }
    abstract double calculateFee();
}
class RegularStudent extends Student{
    int units;
    double rate;

    RegularStudent(String name, int units, double rate){
        super(name);
        this.units = units;
        this.rate = rate;
    }
    @Override
    double calculateFee(){
        return units * rate;
    }
}
class ScholarshipStudent extends Student{
    int units;
    double rate;
    double discountPercent;

    ScholarshipStudent(String name, int units, double rate, double discountPercent){
        super(name);
        this.units = units;
        this.rate = rate;
        this.discountPercent = discountPercent;
    }
    @Override
    double calculateFee(){
        double total = units * rate;
        return total - (total * discountPercent / 100);
    }
}
class GraduateStudent extends Student{
    int units;
    double rate, thesisFee;

    GraduateStudent(String name, int units, double rate, double thesisFee){
        super(name);
        this.units = units;
        this.rate = rate;
        this.thesisFee = thesisFee;
    }
    @Override
    double calculateFee(){
        return (units * rate) + thesisFee;
    }
}

public class Polymorphism{
    public static void main(String [] args){
        Calculator c1 = new Calculator();
        System.out.println("Product of 2 integers: " + c1.multiply(5, 10));
        System.out.println("Product of 3 integers: " + c1.multiply(4, 5, 6));
        System.out.println("Product of decimal numbers: " + c1.multiply(3.5, 4.5));

        Vehicle v1 = new Car();
        Vehicle v2 = new Motorcycle();
        Vehicle v3 = new Bus();
        v1.move("Car");
        v2.move("Motorcycle");
        v3.move("Bus");

        Student[] students = {
            new RegularStudent("Juan", 26, 500),
            new ScholarshipStudent("Maria", 25, 500, 20),
            new GraduateStudent("Carlo", 27, 600, 1500)
        };
        for(Student s : students){
            System.out.println(s.name + " - Total Fees (PHP) " + s.calculateFee());
        }
        /*
        Flexibility: calculateFee() method is only called once per every type of student.
        Maintainability: If the formula is changed for one type of student, only one class is needed to edit.
        Reusability: Only one loop and method that accepts Student will be used for all of the type.
        Extensibility: You can add another child class by extending the parent class and overriding the calculateFee() without editing the existing code.
        */
    }
}