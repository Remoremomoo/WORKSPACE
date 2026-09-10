import java.util.Scanner;

class Library{
    private Book[] books = new Book[100];
    private Member[] members = new Member[50];
    private int bookCounter = 0, memberCounter = 0;

    public void addBook(Book b){
        if(bookCounter >= books.length){
            System.out.println("BOOK OVERLOAD!");
            return;
        }
        else{
            books[bookCounter] = b;
            bookCounter++;
            System.out.println("Book Added!");
        }
    }
    public void registerMember(Member m){
        if(memberCounter >= members.length){
            System.out.println("MAXIMUM MEMBER REGISTRY!");
            return;
        }
        else{
            members[memberCounter] = m;
            memberCounter++;
        }
    }
    public void borrowBook(String memID, String isbn){
        int iBook = -1, iMember = -1;
        for(int i = 0; i < bookCounter; i++){
            if(books[i].getIsbn().equals(isbn)){
                iBook = i;
                break;
            }
        }
        for(int i = 0; i < memberCounter; i++){
            if(members[i].getMem().equals(memID)){
                iMember = i;
                break;
            }
        }
        if(iMember == -1){
            System.out.println("MEMBER NOT FOUND!");
            return;
        }
        if(iBook == -1){
            System.out.println("BOOK NOT FOUND!");
            return;
        }
        if(!books[iBook].getStatus().equalsIgnoreCase("available")){
            System.out.println("BOOK NOT AVAILABLE");
            return;
        }
        if(members[iMember].getBorrowed() >= Member.MAX){
            System.out.println("MEMBER HAS REACHED BORROWING LIMIT!");
            return;
        }

        books[iBook].setStatus("Borrowed");
        members[iMember].addBorrowed();
        System.out.println("Book Borrowed Successfully!");
    }
    public void returnBook(String memID, String isbn){
        int iBook = -1, iMember = -1;

        for(int i = 0; i < bookCounter; i++){
            if(books[i].getIsbn().equals(isbn)){
                iBook = i;
                break;
            }
        }
        for(int i = 0; i < memberCounter; i++){
            if(members[i].getMem().equals(memID)){
                iMember = i;
                break;
            }
        }

        if(iBook == -1){
            System.out.println("BOOK NOT FOUND!");
            return;
        }
        if(iMember == -1){
            System.out.println("MEMBER NOT FOUND!");
            return;
        }
        if(books[iBook].getStatus().equalsIgnoreCase("Available")){
            System.out.println("THIS BOOK WAS NOT BORROWED!");
            return;
        }

        books[iBook].setStatus("Available");
        System.out.println("Book Returned Successfully!");
    }

}
class Member{
    static final int MAX = 3;
    static int i = 0;
    private String name, contactNumber, memberID;
    private int borrowedBooks = 0;

    Member(String n, String cN){
        i++;
        this.name = n;
        this.contactNumber = cN;
        this.memberID = "Mem" + i;
        System.out.println("Registered Name: " + this.name);
        System.out.println("Registered Contact Number: " + this.contactNumber);
        System.out.println("Member ID: " + this.memberID);
    }

    public String getName(){
        return name;
    }
    public String getContact(){
        return contactNumber;
    }
    public String getMem(){
        return memberID;
    }
    public int getBorrowed(){
        return borrowedBooks;
    }

    public void addBorrowed(){
        borrowedBooks++;
    }
}
class Book{
    private String author, title, isbn, status = "Available";

    Book(String a, String t, String i){
        this.author = a;
        this.title = t;
        this.isbn = i;
    }
    public String getAuthor(){
        return author;
    }
    public String getTitle(){
        return title;
    }
    public String getIsbn(){
        return isbn;
    }
    public String getStatus(){
        return status;
    }
    public void setStatus(String changeStatus){
        this.status = changeStatus;
    }
}

public class LibrarySystem{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Library lib = new Library();
        int ch;
        String n, cN, a, t, i, mID, isbn;

        do{
            System.out.println("\n--- LIBRARY MANAGEMENT SYSTEM ---");
            System.out.println("1. Add Book");
            System.out.println("2. Register Member");
            System.out.println("3. Borrow Book");
            System.out.println("4. Return Book");
            System.out.println("5. Exit");
            System.out.print("Choice: ");
            ch = sc.nextInt();
            sc.nextLine(); // clear leftover newline

            switch(ch){
                case 1:
                    System.out.print("Author: ");
                    a = sc.nextLine();
                    System.out.print("Title: ");
                    t = sc.nextLine();
                    System.out.print("ISBN: ");
                    i = sc.nextLine();
                    lib.addBook(new Book(a, t, i));
                    break;

                case 2:
                    System.out.print("Name: ");
                    n = sc.nextLine();
                    System.out.print("Contact Number: ");
                    cN = sc.nextLine();
                    lib.registerMember(new Member(n, cN));
                    break;

                case 3:
                    System.out.print("Member ID: ");
                    mID = sc.nextLine();
                    System.out.print("ISBN: ");
                    isbn = sc.nextLine();
                    lib.borrowBook(mID, isbn);
                    break;

                case 4:
                    System.out.print("Member ID: ");
                    mID = sc.nextLine();
                    System.out.print("ISBN: ");
                    isbn = sc.nextLine();
                    lib.returnBook(mID, isbn);
                    break;

                case 5:
                    System.out.println("Exiting... Goodbye!");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }
        } while(ch != 5);

        sc.close();
    }
}