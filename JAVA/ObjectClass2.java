import java.io.IOException;
import java.util.Scanner;

public class ObjectClass2{
    String brand, camera, os, screen, speaker, chargingPort, processor;
    int storage, price, ram;

    ObjectClass2(String brand, int price){
        this.brand = brand;
        this.price = price;
        System.out.println("Phone: " + this.brand);
        System.out.println("Price: " + this.price);
    }

    ObjectClass2(String brand, int price, int storage, int ram){
        this.brand = brand;
        this.price = price;
        this.storage = storage;
        this.ram = ram;
        System.out.println("Phone: " + this.brand);
        System.out.println("Price: " + this.price);
        System.out.println("Storage: " + this.storage + "GB");
        System.out.println("RAM: " + this.ram + "GB");
    }

    ObjectClass2(String brand, int price, int storage, int ram, String camera, String screen, String speaker, String chargingPort, String processor, String os){
        this.brand = brand;
        this.price = price;
        this.storage = storage;
        this.ram = ram;
        this.camera = camera;
        this.screen = screen;
        this.speaker = speaker;
        this.chargingPort = chargingPort;
        this.processor = processor;
        this.os = os;
        System.out.println("PHONE (FULL SPECS)");
        System.out.println("Brand: " + this.brand);
        System.out.println("Price: " + this.price);
        System.out.println("Storage: " + this.storage + "GB");
        System.out.println("RAM: " + this.ram + "GB");
        System.out.println("Camera: " + this.camera);
        System.out.println("Screen: " + this.screen);
        System.out.println("Speaker: " + this.speaker);
        System.out.println("Charging Port: " + this.chargingPort);
        System.out.println("Processor: " + this.processor);
        System.out.println("OS: " + this.os);
    }

    void camCapture(){
        String osName = System.getProperty("os.name").toLowerCase();

        try{
            if(osName.contains("win")){
                new ProcessBuilder("cmd", "/c", "start", "microsoft.windows.camera:").start();
            }
            else if(osName.contains("mac")){
                new ProcessBuilder("open", "-a", "Photo Booth").start();
            }
            else if(osName.contains("nux") || osName.contains("nix")){
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
        String osName = System.getProperty("os.name").toLowerCase();

        try{
            if(osName.contains("win")){
                new ProcessBuilder("cmd", "/c", "start", "ms-callvoicerecorder:").start();
            }
            else if(osName.contains("mac")){
                new ProcessBuilder("open", "-a", "QuickTime Player").start();
            }
            else if(osName.contains("nux") || osName.contains("nix")){
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
        String osName = System.getProperty("os.name").toLowerCase();

        try{
            if(osName.contains("win")){
                new ProcessBuilder("cmd", "/c", "start", "ms-phone:").start();
            }
            else if(osName.contains("mac")){
                new ProcessBuilder("open", "-a", "FaceTime").start();
            }
            else if(osName.contains("nux") || osName.contains("nix")){
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
        String osName = System.getProperty("os.name").toLowerCase();

        try{
            if(osName.contains("win")){
                new ProcessBuilder("cmd", "/c", "start", "microsoft.microsoftsolitairecollection:").start();
            }
            else if(osName.contains("mac")){
                new ProcessBuilder("open", "-a", "Chess").start();
            }
            else if(osName.contains("nux") || osName.contains("nix")){
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
        String osName = System.getProperty("os.name").toLowerCase();

        try{
            if(osName.contains("win")){
                new ProcessBuilder("cmd", "/c", "start", "ms-people:").start();
            }
            else if(osName.contains("mac")){
                new ProcessBuilder("open", "-a", "Messages").start();
            }
            else if(osName.contains("nux") || osName.contains("nix")){
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
        Scanner sc = new Scanner(System.in);

        System.out.println("PHONE (INITIALIZE)");
        System.out.println();
        System.out.println("Brand Name: ");
        String brand = sc.nextLine();

        System.out.println("Price (in Peso): ");
        int price = Integer.parseInt(sc.nextLine());

        System.out.println("Add specs? [y/n]: ");
        String addSpecs = sc.nextLine();

        ObjectClass2 ptr;

        if(addSpecs.equalsIgnoreCase("n")){
            ptr = new ObjectClass2(brand, price);
        }
        else{
            System.out.println("Storage (in GB): ");
            int storage = Integer.parseInt(sc.nextLine());

            System.out.println("RAM (in GB): ");
            int ram = Integer.parseInt(sc.nextLine());

            System.out.println("Add full details? [y/n]: ");
            String addFull = sc.nextLine();

            if(addFull.equalsIgnoreCase("n")){
                ptr = new ObjectClass2(brand, price, storage, ram);
            }
            else{
                System.out.println("Camera: ");
                String camera = sc.nextLine();
                System.out.println("Screen: ");
                String screen = sc.nextLine();
                System.out.println("Speaker: ");
                String speaker = sc.nextLine();
                System.out.println("Charging Port: ");
                String chargingPort = sc.nextLine();
                System.out.println("Processor: ");
                String processor = sc.nextLine();
                System.out.println("Operating System: ");
                String os = sc.nextLine();

                ptr = new ObjectClass2(brand, price, storage, ram, camera, screen, speaker, chargingPort, processor, os);
            }
        }

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