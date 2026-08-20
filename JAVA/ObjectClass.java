import java.io.IOException;
import java.util.Scanner;

public class ObjectClass{
    String brand, camera, os, screen, speaker, chargingPort, processor;
    int storage, price, ram;

    void camCapture(){
        String os = System.getProperty("os.name").toLowerCase();

        try{
            if(os.contains("win")){
                new ProcessBuilder("cmd", "/c", "start", "microsoft.windows.camera:").start();
            }
            else if(os.contains("mac")){
                new ProcessBuilder("open", "-a", "Photo Booth").start();
            }
            else if(os.contains("nux") || os.contains("nix")){
                new ProcessBuilder("cheese").start();
            }
            else{
                System.out.println("OS NOT SUPPORTED!");
                return;
            }
            System.out.println("Opening camera...");
        }
         catch (IOException e){
             System.out.println("CAMERA ERROR!: " + e.getMessage());
        }
    }

    void voiceCapture(){
        String os = System.getProperty("os.name").toLowerCase();

        try{
            if(os.contains("win")){
                new ProcessBuilder("cmd", "/c", "start", "ms-callvoicerecorder:").start();
            }
            else if(os.contains("mac")){
                new ProcessBuilder("open", "-a", "QuickTime Player").start();
            }
            else if(os.contains("nux") || os.contains("nix")){
                new ProcessBuilder("gnome-sound-recorder").start();
            }
            else{
                System.out.println("OS NOT SUPPORTED!");
                return;
            }
            System.out.println("Opening voice recorder...");
        }
        catch(IOException e){
            System.out.println("VOICE RECORDER ERROR!: " + e.getMessage());
        }
    }

    void takeCall(){
        String os = System.getProperty("os.name").toLowerCase();

        try{
            if(os.contains("win")){
                new ProcessBuilder("cmd", "/c", "start", "ms-phone:").start();
            }
            else if(os.contains("mac")){
                new ProcessBuilder("open", "-a", "FaceTime").start();
            }
            else if(os.contains("nux") || os.contains("nix")){
                System.out.println("No calling application available");
                return;
            }
            else{
                System.out.println("OS NOT SUPPORTED!");
                return;
            }
            System.out.println("Opening call manager...");
        }
        catch(IOException e){
            System.out.println("CALL ERROR!" + e.getMessage());
        }
    }

    void openGame(){
        String os = System.getProperty("os.name").toLowerCase();

        try{
            if(os.contains("win")){
                new ProcessBuilder("cmd", "/c", "start", "microsoft.microsoftsolitairecollection:").start();
            }
            else if(os.contains("mac")){
                new ProcessBuilder("open", "-a", "Chess").start();
            }
            else if(os.contains("nux") || os.contains("nix")){
                new ProcessBuilder("gnome-mines").start();
            }
            else{
                System.out.println("OS NOT SUPPORTED!");
                return;
            }
            System.out.println("Opening game...");
        }
        catch(IOException e){
            System.out.println("GAME ERROR!" + e.getMessage());
            return;
        }
    }

    void getMessage(){
        String os = System.getProperty("os.name").toLowerCase();

        try{
            if(os.contains("win")){
                new ProcessBuilder("cmd", "/c", "start", "ms-people:").start();
            }
            else if(os.contains("mac")){
                new ProcessBuilder("open", "-a", "Messages").start();
            }
            else if(os.contains("nux") || os.contains("nix")){
                System.out.println("No messaging application available");
                return;
            }
            else{
                System.out.println("OS NOT SUPPORTED!");
                return;
            }
            System.out.println("Opening messages...");
        }
        catch(IOException e){
            System.out.println("MESSAGE ERROR!" + e.getMessage());
            return;
        }
    }

    public static void main(String[] args){
        ObjectClass ptr = new ObjectClass();
        Scanner sc = new Scanner(System.in);

        System.out.println("PHONE (INITIALIZE)");
        System.out.println();
        System.out.println("Brand Name: ");
        ptr.brand = sc.nextLine();

        System.out.println("Storage (in GB): ");
        ptr.storage = Integer.parseInt(sc.nextLine());
        
        System.out.println("RAM (in GB): ");
        ptr.ram = Integer.parseInt(sc.nextLine());

        System.out.println("Price (in Peso): ");
        ptr.price = Integer.parseInt(sc.nextLine());

        System.out.println("Camera: ");
        ptr.camera = sc.nextLine();
        System.out.println("Screen: ");
        ptr.screen = sc.nextLine();
        System.out.println("Speaker: ");
        ptr.speaker = sc.nextLine();
        System.out.println("Charging Port: ");
        ptr.chargingPort = sc.nextLine();
        System.out.println("Processor: ");
        ptr.processor = sc.nextLine();
        System.out.println("Operating System: ");
        ptr.os = sc.nextLine();

        boolean running = true;
        while(running){
            System.out.println("ACTIONS: ");
            System.out.println();
            System.out.print("1. Camera\n2. Voice Recorder\n3. Call\n4. Play Game\n5. Send Message\n6. Exit\n\n");
            System.out.println("Choose [1-6]: ");
            int choice = Integer.parseInt(sc.nextLine());
            
            switch(choice){
                case 1:
                    ptr.camCapture();
                    break;
                case 2:
                    ptr.voiceCapture();
                    break;
                case 3:
                    ptr.takeCall();
                    break;
                case 4:
                    ptr.openGame();
                    break;
                case 5:
                    ptr.getMessage();
                    break;
                case 6:
                    running = false;
                    System.out.println("Closing...");
                    break;
                default:
                    System.out.println("INVALID ACTION!");
                    break;
            }
        }
        sc.close();
    }
}