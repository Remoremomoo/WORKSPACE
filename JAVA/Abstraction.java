import java.util.Scanner;

interface Notification{
    void sendNotif(String receiver);
}
class EmailNotif implements Notification{
    @Override
    public void sendNotif(String receiver){
        System.out.println("Email sent to: " + receiver);
    }
}
class SMSNotif implements Notification{
    @Override
    public void sendNotif(String receiver){
        System.out.println("SMS sent to: " + receiver);
    }
}

public class Abstraction{
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        Notification email = new EmailNotif();
        Notification sms = new SMSNotif();

        System.out.println("Enter receiver email: ");
        String emailAd = sc.nextLine();
        System.out.println("Enter receiver SMS number: ");
        String smsNum = sc.nextLine();

        email.sendNotif(emailAd);
        sms.sendNotif(smsNum);

        sc.close();
    }
}

/*
    1. I declared it as an interface because it only defines what a notification must do 
    (sendNotif), not how it is done. Email and SMS send notifications differently, 
    so the interface acts as a common contract without forcing any implementation.
    
    2. It means the class agrees to follow the contract of the Notification interface. 
    EmailNotif and SMSNotif promise to provide their own version of every method declared 
    in Notification. If they don’t, the code will not compile.
    
    3. Because sendNotif() is an abstract method in the interface, and any class that 
    implements an interface must implement all of its abstract methods. This guarantees 
    that every Notification object can be called with sendNotif(), whether it is an email or an SMS.
    
    4. To add a new type, like PushNotif, I only need to create a new class that implements 
    Notification and defines sendNotif(). The existing classes and the code that uses 
    Notification don’t need to change, so the program is easy to extend.
    
    5. Abstraction is the concept of hiding the details and showing only what is essential. 
    Interface is the Java tool used to achieve that. In my program, the abstraction is that 
    main only knows it can call sendNotif() on a Notification. It doesn’t need to know how an 
    email or SMS is actually sent. The interface is the Notification itself, the contract that 
    makes this possible by declaring sendNotif() and leaving the implementation to EmailNotif and SMSNotif.
*/