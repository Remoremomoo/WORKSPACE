import javax.swing.*;
import java.awt.*;

public class NumberSystemCalculatorUI extends JFrame {
    static final String[] BASES = {"2", "8", "10", "16"};
    static final String[] OPS = {"+", "-", "*", "/"};

    JComboBox<String> mode = new JComboBox<>(new String[]{"Arithmetic", "Convert only"});
    JComboBox<String> base1 = new JComboBox<>(BASES);
    JTextField num1 = new JTextField(12);
    JComboBox<String> op = new JComboBox<>(OPS);
    JComboBox<String> base2 = new JComboBox<>(BASES);
    JTextField num2 = new JTextField(12);
    JComboBox<String> outBase = new JComboBox<>(BASES);
    JButton calcButton = new JButton("Calculate");
    JLabel trialsLabel = new JLabel();
    JLabel resultLabel = new JLabel("Result: ");

    int trialsLeft = 3;

    NumberSystemCalculatorUI(){
        setTitle("Number System Calculator");
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        JPanel form = new JPanel(new GridLayout(0, 2, 8, 8));
        form.setBorder(BorderFactory.createEmptyBorder(12, 12, 12, 12));
        form.add(new JLabel("Mode"));                form.add(mode);
        form.add(new JLabel("1st number base"));     form.add(base1);
        form.add(new JLabel("1st number"));          form.add(num1);
        form.add(new JLabel("Operation"));           form.add(op);
        form.add(new JLabel("2nd number base"));     form.add(base2);
        form.add(new JLabel("2nd number"));          form.add(num2);
        form.add(new JLabel("Show result in base")); form.add(outBase);
        form.add(trialsLabel);                       form.add(calcButton);

        resultLabel.setBorder(BorderFactory.createEmptyBorder(0, 12, 12, 12));

        add(form, BorderLayout.CENTER);
        add(resultLabel, BorderLayout.SOUTH);

        mode.addActionListener(e -> toggleArithmeticFields());
        calcButton.addActionListener(e -> onCalculate());

        toggleArithmeticFields();
        updateTrialsLabel();
        pack();
        setLocationRelativeTo(null);
    }

    void toggleArithmeticFields(){
        boolean arith = mode.getSelectedIndex() == 0;
        op.setEnabled(arith);
        base2.setEnabled(arith);
        num2.setEnabled(arith);
    }

    void updateTrialsLabel(){
        trialsLabel.setText("Trials left: " + trialsLeft);
    }

    void onCalculate(){
        if(trialsLeft == 0){
            if(runQuiz()){
                trialsLeft = 3;
                updateTrialsLabel();
                resultLabel.setText("Correct! +3 trials.");
            }
            else{
                calcButton.setEnabled(false);
                resultLabel.setText("Wrong! Calculator locked.");
            }
            return;
        }

        boolean done;
        if(mode.getSelectedIndex() == 0){
            done = doArithmetic();
        }
        else{
            done = doConvertOnly();
        }

        if(done){
            trialsLeft--;
            updateTrialsLabel();
        }
    }

    boolean doArithmetic(){
        int b1 = Integer.parseInt((String) base1.getSelectedItem());
        int b2 = Integer.parseInt((String) base2.getSelectedItem());
        int out = Integer.parseInt((String) outBase.getSelectedItem());
        String n1 = num1.getText().trim().toUpperCase();
        String n2 = num2.getText().trim().toUpperCase();
        char opChar = ((String) op.getSelectedItem()).charAt(0);

        if(n1.length() == 0 || n2.length() == 0){
            resultLabel.setText("Please fill in both numbers!");
            return false;
        }

        String bin1 = NumberSystemCalculator.convertToBinary(n1, b1);
        String bin2 = NumberSystemCalculator.convertToBinary(n2, b2);

        String stored;
        String storedRemainder = "";

        if(opChar == '+'){
            stored = NumberSystemCalculator.addBinary(bin1, bin2);
        }
        else if(opChar == '-'){
            if(NumberSystemCalculator.compareBinary(bin1, bin2) < 0){
                resultLabel.setText("Result would be negative!");
                return false;
            }
            stored = NumberSystemCalculator.subtractRaw(bin1, bin2);
        }
        else if(opChar == '*'){
            stored = NumberSystemCalculator.multiplyBinary(bin1, bin2);
        }
        else{
            if(bin2.equals("0")){
                resultLabel.setText("Cannot divide by zero!");
                return false;
            }
            stored = NumberSystemCalculator.divideBinary(bin1, bin2, false);
            storedRemainder = NumberSystemCalculator.divideBinary(bin1, bin2, true);
        }

        if(opChar == '/'){
            resultLabel.setText("<html>Quotient: " + NumberSystemCalculator.convertFromBinary(stored, out)
                + "<br>Remainder: " + NumberSystemCalculator.convertFromBinary(storedRemainder, out) + "</html>");
        }
        else{
            resultLabel.setText("Result: " + NumberSystemCalculator.convertFromBinary(stored, out));
        }
        return true;
    }

    boolean doConvertOnly(){
        int fromBase = Integer.parseInt((String) base1.getSelectedItem());
        int toBase = Integer.parseInt((String) outBase.getSelectedItem());
        String n1 = num1.getText().trim().toUpperCase();

        if(n1.length() == 0){
            resultLabel.setText("Please fill in the number!");
            return false;
        }

        String bin = NumberSystemCalculator.convertToBinary(n1, fromBase);
        resultLabel.setText("Result: " + NumberSystemCalculator.convertFromBinary(bin, toBase));
        return true;
    }

    boolean runQuiz(){
        int[] bases = {2, 8, 10, 16};
        int n = (int)(Math.random() * 255) + 1;
        int a = bases[(int)(Math.random() * 4)];
        int b = a;
        while(b == a){
            b = bases[(int)(Math.random() * 4)];
        }

        String question = NumberSystemCalculator.convertFromBinary(NumberSystemCalculator.convertToBinary("" + n, 10), a);
        String answer =   NumberSystemCalculator.convertFromBinary(NumberSystemCalculator.convertToBinary(question, a), b);

        String reply = JOptionPane.showInputDialog(this,
            "Trials used up! Convert " + question + " (base " + a + ") to base " + b + ":",
            "Quiz", JOptionPane.QUESTION_MESSAGE);

        if(reply == null){
            return false;
        }

        reply = NumberSystemCalculator.removeZeroes(reply.trim().toUpperCase());
        return reply.equals(answer);
    }

    public static void main(String[] args){
        SwingUtilities.invokeLater(() -> new NumberSystemCalculatorUI().setVisible(true));
    }
}