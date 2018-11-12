package seiot.modulo_lab_2_2.msg;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JProgressBar;
import javax.swing.SwingConstants;

public class SimpleGUI extends JFrame {

    private static final int NC = 10;
    private JPanel jp;
    private JButton jb;
    private JLabel title;
    private JLabel text;
    private JProgressBar bar;
    private JPanel minPanel;
    private Model model;

    public SimpleGUI() throws Exception {
        this.setSize((int) (getToolkit().getScreenSize().width * 0.5),
                (int) (getToolkit().getScreenSize().height * 0.5));
        this.model = new ModelImpl();
        this.model.connectArduino();
        BorderLayout bl1 = new BorderLayout();
        this.jp = new JPanel(bl1);
        this.jb = new JButton("Ricarica caffe'");
        this.title = new JLabel("Coffee Machine", SwingConstants.CENTER);
        this.text = new JLabel("Testo", SwingConstants.CENTER);
        this.text.setFont(new Font("Helvetica", Font.TYPE1_FONT, 20));
        this.title.setFont(new Font("Helvetica", Font.BOLD, 32));
        this.title.setForeground(Color.BLUE);
        this.bar = new JProgressBar(0,5);
        this.bar.setSize((int) (this.getSize().width * 0.7), (int) (this.getSize().height * 0.1));
        this.bar.setValue(2);

        jp.add(title, BorderLayout.NORTH);
        this.minPanel = new JPanel(new BorderLayout());
        minPanel.add(text, BorderLayout.NORTH);
        minPanel.add(bar, BorderLayout.CENTER);
        jp.add(minPanel, BorderLayout.CENTER);
        jp.add(jb, BorderLayout.SOUTH);

        this.getContentPane().add(jp);
        this.setVisible(true);
        this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);

        jb.addActionListener(e -> {
            try {
                this.model.rechargeCoffee(String.valueOf(NC));
            } catch (Exception e1) {
                e1.printStackTrace();
            }
        });

    }

    public void msgCicle() throws Exception {
        while (true) {
            String msg = this.model.receiveStatus();
            if (msg.equals("M")) {
                this.text.setText("Make Coffee.");
            } else if (msg.equals("W")) {
                this.text.setText("Welcome!");
            } else if (msg.equals("R")) {
                this.text.setText("Coffee is ready.");
            } else if (msg.equals("N")) {
                this.text.setText("No more coffee. Waiting for recharge");
            } else {
                this.bar.setValue(Integer.parseInt(msg));
            }
        }
    }

    public static void main(String[] args) throws Exception {
        SimpleGUI gui = new SimpleGUI();
        gui.msgCicle();

    }
}
