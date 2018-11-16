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

import seiot.modulo_lab_2_2.msg.jssc.SerialCommChannel;

public class SimpleGUI extends JFrame {

    /**
     * 
     */
    private static final long serialVersionUID = 1L;
    private static final int NC = 10;
    private JPanel jp;
    private JButton jb;
    private JLabel title;
    private JLabel text;
    private JProgressBar bar;
    private JPanel minPanel;
    private SerialCommChannel channel;

    public SimpleGUI() throws Exception {

        channel = new SerialCommChannel("/dev/cu.usbmodem1411", 9600);

        this.setSize((int) (getToolkit().getScreenSize().width * 0.5),
                (int) (getToolkit().getScreenSize().height * 0.5));

        BorderLayout bl1 = new BorderLayout();
        this.jp = new JPanel(bl1);
        this.jb = new JButton("Ricarica caffe'");
        this.title = new JLabel("Coffee Machine", SwingConstants.CENTER);
        this.text = new JLabel("", SwingConstants.CENTER);
        this.text.setFont(new Font("Helvetica", Font.TYPE1_FONT, 20));
        this.title.setFont(new Font("Helvetica", Font.BOLD, 32));
        this.title.setForeground(Color.BLUE);
        this.bar = new JProgressBar(0, 4);
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
                channel.sendMsg(String.valueOf(NC));
            } catch (Exception e1) {
                e1.printStackTrace();
            }
        });

        System.out.println("Waiting Arduino for rebooting...");
        Thread.sleep(4000);
        System.out.println("Ready.");

    }

    public static void main(String[] args) throws Exception {

        SimpleGUI gui = new SimpleGUI();

        while (true) {
            String msg = gui.channel.receiveMsg();
            msg = msg.trim();
            if (msg.equals("M")) {
                gui.text.setText("Make Coffee.");
            } else if (msg.equals("W")) {
                gui.text.setText("Welcome!");
            } else if (msg.equals("A")) {
                gui.text.setText("Stand By");
            } else if (msg.equals("R")) {
                gui.text.setText("Coffee is ready.");
            } else if (msg.equals("N")) {
                gui.text.setText("No more coffee. Waiting for recharge");
            } else if (msg.equals("F")) {
                gui.text.setText("");
            } else if (msg.equals("C")) {
                gui.text.setText("Coffee refilled");
                Thread.sleep(1000);
                gui.text.setText("");
            } else {
                gui.bar.setValue(Integer.parseInt(msg));
            }
        }

    }
}
