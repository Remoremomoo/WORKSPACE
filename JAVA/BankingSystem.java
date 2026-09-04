import java.util.Scanner;

public class BankingSystem {
    String customerName, accStatus;
    long cardID;

    BankingSystem(String name){
        this.customerName = name;
        System.out.println("Customer Name: " + this.customerName);
        System.out.println("Status: Card Not Issued Yet");
    }
    BankingSystem(String name, long ID, String status){
        this.customerName = name;
        this.cardID = ID;
        this.accStatus = status;
        System.out.println("Customer Name: " + this.customerName);
        System.out.println("Card ID: " + this.cardID);
        System.out.println("Card Status: " + this.accStatus);
    }

    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        String nm, stat, choice1;
        long id;

        System.out.println("Enter Account Name: ");
        nm = sc.nextLine();
        System.out.println("Card ID Available? [y/n]: ");
        choice1 = sc.nextLine();

        if(choice1.equalsIgnoreCase("y")){
            System.out.println("Enter Card ID: ");
            id = sc.nextLong();
            sc.nextLine();

            System.out.println("Card Status: ");
            stat = sc.nextLine();

            BankingSystem user1 = new BankingSystem(nm, id, stat);
        }
        else{
            BankingSystem user1 = new BankingSystem(nm);
        }
        sc.close();
    }
}
