import javax.swing.*;
import java.awt.*;

public class CalculatorUI extends JFrame{
    static final String[] BASES = {"2", "8", "10", "16"};
    static final String[] OPS = {"+", "-", "*", "/"};

    JComboBox<String> mode = new JComboBox<>(new String[]{"Arithmetic", "Convert only"});
    JComboBox<String> base1 = new JComboBox<>(BASES);
    JComboBox<String> base2 = new JComboBox<>(BASES);
    JComboBox<String> op = new JComboBox<>(OPS);
    JComboBox<String> outBase = new JComboBox<>(BASES);
    JTextField num1 = new JTextField(12);
    JTextField num2 = new JTextField(12);
    JLabel trialsLabel = new JLabel();
    JLabel resultLabel = new JLabel("Result: ");
    JButton go = new JButton("Calculate");
    int trialsLeft = 3;

    CalculatorUI(){
        setTitle("Number System Calculator");
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        JPanel p = new JPanel(new GridLayout(0, 2, 8, 8));
        p.setBorder(BorderFactory.createEmptyBorder(12, 12, 12, 12));
        p.add(new JLabel("Mode"));                p.add(mode);
        p.add(new JLabel("1st number base"));     p.add(base1);
        p.add(new JLabel("1st number"));          p.add(num1);
        p.add(new JLabel("Operation"));           p.add(op);
        p.add(new JLabel("2nd number base"));     p.add(base2);
        p.add(new JLabel("2nd number"));          p.add(num2);
        p.add(new JLabel("Show result in base")); p.add(outBase);
        p.add(trialsLabel);                       p.add(go);

        resultLabel.setBorder(BorderFactory.createEmptyBorder(0, 12, 12, 12));
        add(p, BorderLayout.CENTER);
        add(resultLabel, BorderLayout.SOUTH);

        mode.addActionListener(e -> {
            boolean arith = mode.getSelectedIndex() == 0;
            op.setEnabled(arith);
            base2.setEnabled(arith);
            num2.setEnabled(arith);
        });

        go.addActionListener(e -> calculate());

        updateTrials();
        pack();
        setLocationRelativeTo(null);
    }

    void updateTrials(){
        trialsLabel.setText("Trials left: " + trialsLeft);
    }

    boolean valid(String s, int base){
        if(s.length() == 0){
            return false;
        }
        for(int i = 0; i < s.length(); i++){
            int v = NumberSystemCalculator.DIGITFORMAT.indexOf(s.charAt(i));
            if(v < 0 || v >= base){
                return false;
            }
        }
        return true;
    }

    void calculate(){
        if(trialsLeft == 0){
            askQuiz();
            return;
        }

        int b1 = Integer.parseInt((String) base1.getSelectedItem());
        int b2 = Integer.parseInt((String) base2.getSelectedItem());
        int out = Integer.parseInt((String) outBase.getSelectedItem());
        String n1 = num1.getText().trim().toUpperCase();
        String n2 = num2.getText().trim().toUpperCase();
        boolean arith = mode.getSelectedIndex() == 0;

        if(!valid(n1, b1) || (arith && !valid(n2, b2))){
            resultLabel.setText("Invalid number for the chosen base!");
            return;
        }

        String bin1 = NumberSystemCalculator.convertToBinary(n1, b1);

        if(!arith){
            resultLabel.setText("Result: " + NumberSystemCalculator.convertFromBinary(bin1, out));
            trialsLeft--;
            updateTrials();
            return;
        }

        String bin2 = NumberSystemCalculator.convertToBinary(n2, b2);
        String o = (String) op.getSelectedItem();
        String stored;
        String storedRemainder = "";

        if(o.equals("+")){
            stored = NumberSystemCalculator.addBinary(bin1, bin2);
        }
        else if(o.equals("-")){
            if(NumberSystemCalculator.compareBinary(bin1, bin2) < 0){
                resultLabel.setText("Result would be negative!");
                return;
            }
            stored = NumberSystemCalculator.subtractRaw(bin1, bin2);
        }
        else if(o.equals("*")){
            stored = NumberSystemCalculator.multiplyBinary(bin1, bin2);
        }
        else{
            if(bin2.equals("0")){
                resultLabel.setText("Cannot divide by zero!");
                return;
            }
            stored = NumberSystemCalculator.divideBinary(bin1, bin2, false);
            storedRemainder = NumberSystemCalculator.divideBinary(bin1, bin2, true);
        }

        if(o.equals("/")){
            resultLabel.setText("<html>Quotient: " + NumberSystemCalculator.convertFromBinary(stored, out)
                + "<br>Remainder: " + NumberSystemCalculator.convertFromBinary(storedRemainder, out) + "</html>");
        }
        else{
            resultLabel.setText("Result: " + NumberSystemCalculator.convertFromBinary(stored, out));
        }
        trialsLeft--;
        updateTrials();
    }

    void askQuiz(){
        int[] bases = {2, 8, 10, 16};
        int n = (int)(Math.random() * 255) + 1;
        int a = bases[(int)(Math.random() * 4)];
        int b = a;
        while(b == a){
            b = bases[(int)(Math.random() * 4)];
        }

        String question = NumberSystemCalculator.convertFromBinary(NumberSystemCalculator.convertToBinary("" + n, 10), a);
        String answer = NumberSystemCalculator.convertFromBinary(NumberSystemCalculator.convertToBinary(question, a), b);

        String reply = JOptionPane.showInputDialog(this,
            "Trials used up! Convert " + question + " (base " + a + ") to base " + b + ":",
            "Quiz", JOptionPane.QUESTION_MESSAGE);

        if(reply != null && NumberSystemCalculator.removeZeroes(reply.trim().toUpperCase()).equals(answer)){
            trialsLeft = 3;
            updateTrials();
            resultLabel.setText("Correct! +3 trials.");
        }
        else{
            go.setEnabled(false);
            resultLabel.setText("Wrong! Calculator locked.");
        }
    }

    public static void main(String[] args){
        SwingUtilities.invokeLater(() -> new CalculatorUI().setVisible(true));
    }
}