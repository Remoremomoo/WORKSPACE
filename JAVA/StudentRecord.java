import java.util.Scanner;

public class StudentRecord{
    String name, program;
    int ID;
    StudentRecord(String n){
        this.name = n;
        System.out.println("Student: " + this.name);
        System.out.println("Status: Unregistered");
    }
    StudentRecord(String n, int id){
        this.name = n;
        this.ID = id;
        System.out.println("Student: " + this.name);
        System.out.println("Student ID: " + this.ID);
        System.out.println("Status: Unenrolled");
    }
    StudentRecord(String n, int id, String prog){
        this.name = n;
        this.ID = id;
        this.program = prog;
        System.out.println("Student: " + this.name);
        System.out.println("Student ID: " + this.ID);
        System.out.println("Status: Enrolled");
    }

    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        String nm, pr, choice1, choice2;
        int StudID;

        System.out.println("Enter name: ");
        nm = sc.nextLine();
        System.out.println("Do you have a Student ID?[y/n]: ");
        choice1 = sc.nextLine();
        
        if(choice1.equalsIgnoreCase("y")){
            System.out.println("Enter Student ID: ");
            StudID = sc.nextInt();
            sc.nextLine();

            System.out.println("Are you currently enlisted? [y/n]: ");
            choice2 = sc.nextLine();

            if(choice2.equalsIgnoreCase("y")){
                System.out.println("Enter Program (BS**): ");
                pr = sc.nextLine();
                StudentRecord s1 = new StudentRecord(nm, StudID, pr);
            }
            else{
                StudentRecord s1 = new StudentRecord(nm, StudID);
            }
        }
        else{
            StudentRecord s1 = new StudentRecord(nm);
        }
        sc.close();    
    }
}