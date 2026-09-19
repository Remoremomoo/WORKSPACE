import java.util.Scanner;

public class NumberSystemCalculator{
    static final String DIGITFORMAT = "0123456789ABCDEF";

    static String numberToBits(int value, int length){
        String binaryPrint = "";
        int byTwos;
        if(length == 3){
            byTwos = 4;
        }
        else{
            byTwos = 8;
        }

        while(byTwos >= 1){
            if(value >= byTwos){
                binaryPrint += "1";
                value -= byTwos;
            }
            else{
                binaryPrint += "0";
            }
            byTwos /= 2;
        }
        return binaryPrint;
    }

    static String removeZeroes(String s){
        while(s.length() > 1 && s.charAt(0) == '0'){
            s = s.substring(1);
        }
        return s;
    }
    
    static int compareBinary(String a, String b){
        a = removeZeroes(a);
        b = removeZeroes(b);

        if(a.length() != b.length()){
            if(a.length() > b.length()){
                return 1;
            }
            return -1;
        }

        for(int i = 0; i < a.length(); i++){
            if(a.charAt(i) != b.charAt(i)){
                if(a.charAt(i) > b.charAt(i)){
                    return 1;
                }
                return -1;
            }
        }
        return 0;
    }

    static String convertToBinary(String num, int base){
        if(base == 2){
            return removeZeroes(num);
        }
        if(base == 10){
            int n = 0;
            for(int i = 0; i < num.length(); i++){
                n = n * 10 + (num.charAt(i) - '0');
            }
            if(n == 0){
                return "0";
            }
            String bin = "";
            while(n > 0){
                bin = (n % 2) + bin;
                n = n / 2;
            }
            return bin;
        }

        int width;
        if(base == 8){
                width = 3;
        }
        else{
            width = 4;
        }

        String binaryPrint = "";

        for(int i = 0; i < num.length(); i++){
            char c = num.charAt(i);
            int value = DIGITFORMAT.indexOf(c);
            binaryPrint += numberToBits(value, width);
        }
        return removeZeroes(binaryPrint);
    }

    static String addBinary(String a, String b){
        String result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while(i >= 0 || j >= 0 || carry > 0 ){
            int sum = carry;
            if(i >= 0){
                sum += a.charAt(i--) - '0';
            }
            if(j >= 0){
                sum += b.charAt(j--) - '0';
            }

            result = (sum % 2) + result;
            carry = sum / 2;
        }
        return result;
    }

    static String subtractRaw(String a, String b){
        String result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int borrow = 0;

        while(i >= 0){
            int diff = (a.charAt(i--) - '0') - borrow;
            if(j >= 0){
                diff -= (b.charAt(j--) - '0');
            }

            if(diff < 0){
                diff += 2;
                borrow = 1;
            }
            else{
                borrow = 0;
            }
            result = diff + result;
        }
        return removeZeroes(result);
    }

    static String subtractBinary(String a, String b){
        if(compareBinary(a, b) >= 0){
            return subtractRaw(a, b);
        }
        return "-" + subtractRaw(b, a);
    }

    static String multiplyBinary(String a, String b){
        String result = "0";
        int shift = 0;

        for(int i = b.length() - 1; i >= 0; i--){
            if(b.charAt(i) == '1'){
                String shifted = a;
                for(int k = 0; k < shift; k++){
                    shifted += "0";
                }
                result = addBinary(result, shifted);
            }
            shift++;
        }
        return removeZeroes(result);
    }

    static String divideBinary(String a, String b, boolean wantRemainder){
        String quotient = "";
        String remainder = "0";

        for(int i = 0; i < a.length(); i++){
            // ibaba ang susunod na bit ni a
            remainder = removeZeroes(remainder + a.charAt(i));

            if(compareBinary(remainder, b) >= 0){
                remainder = subtractRaw(remainder, b);
                quotient += "1";
            }
            else{
                quotient += "0";
            }
        }

        if(wantRemainder){
            return remainder;
        }
        return removeZeroes(quotient);
    }

    static String convertFromBinaryPositive(String binary, int toBase){
        if(toBase == 2){
            return binary;
        }
        if(toBase == 10){
            int n = 0;
            for(int i = 0; i < binary.length(); i++){
                n = n * 2 + (binary.charAt(i) - '0');
            }
            return "" + n;
        }

        int width;
        if(toBase == 8){
            width = 3;
        }
        else{
            width = 4;
        }

        while(binary.length() % width != 0){
            binary = "0" + binary;
        }

        String convertPrint = "";
        for(int i = 0; i < binary.length(); i += width){
            int value = 0;
            for(int j = i; j < i + width; j++){
                value = value * 2 + (binary.charAt(j) - '0');
            }
            convertPrint += DIGITFORMAT.charAt(value);
        }
        return removeZeroes(convertPrint);
    }

    static String convertFromBinary(String binary, int toBase){
        if(binary.charAt(0) == '-'){
            return "-" + convertFromBinaryPositive(binary.substring(1), toBase);
        }
        return convertFromBinaryPositive(binary, toBase);
    }
    
    static boolean quiz(Scanner sc){
        int[] bases = {2, 8, 10, 16};

        int n = (int)(Math.random() * 255) + 1;
        int base1 = bases[(int)(Math.random() * 4)];
        int base2 = base1;
        while(base2 == base1){
            base2 = bases[(int)(Math.random() * 4)];
        }

        String question = convertFromBinary(convertToBinary("" + n, 10), base1);
        String answer =   convertFromBinary(convertToBinary(question, base1), base2);

        System.out.println("\nQUIZ: Convert " + question + " (base " + base1 + ") to base " + base2);
        System.out.print("Answer: ");
        String reply = removeZeroes(sc.next().toUpperCase());

        return reply.equals(answer);
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int trialsLeft = 3;

        while(true){
            if(trialsLeft == 0){
                System.out.println("\n[!] Trials used up. Answer the quiz to unlock 3 more trials.");
                if(quiz(sc)){
                    System.out.println("Correct! +3 trials.");
                    trialsLeft = 3;
                }
                else{
                    System.out.println("Wrong! Calculator locked.");
                    break;
                }
            }

            System.out.println("\nTrials left: " + trialsLeft);

            System.out.print("1st number base (2/8/10/16): ");
            int base1 = sc.nextInt();
            System.out.print("1st number: ");
            String n1 = sc.next().toUpperCase();

            System.out.print("2nd number base (2/8/10/16): ");
            int base2 = sc.nextInt();
            System.out.print("2nd number: ");
            String n2 = sc.next().toUpperCase();

            System.out.print("Operation (+, -, *, /): ");
            char op = sc.next().charAt(0);

            String bin1 = convertToBinary(n1, base1);
            String bin2 = convertToBinary(n2, base2);

            String stored;
            String storedRemainder = "";

            if(op == '+'){
                stored = addBinary(bin1, bin2);
            }
            else if(op == '-'){
                stored = subtractBinary(bin1, bin2);
            }
            else if(op == '*'){
                stored = multiplyBinary(bin1, bin2);
            }
            else if(op == '/'){
                if(bin2.equals("0")){
                    System.out.println("Cannot divide by zero!");
                    continue;
                }
                stored = divideBinary(bin1, bin2, false);
                storedRemainder = divideBinary(bin1, bin2, true);
            }
            else{
                System.out.println("Invalid operation!");
                continue;
            }

            System.out.print("Show result in base (2/8/10/16): ");
            int outBase = sc.nextInt();

            if(op == '/'){
                System.out.println("Quotient:  " + convertFromBinary(stored, outBase));
                System.out.println("Remainder: " + convertFromBinary(storedRemainder, outBase));
            }
            else{
                System.out.println("Result: " + convertFromBinary(stored, outBase));
            }

            trialsLeft--;
        }
    }
}