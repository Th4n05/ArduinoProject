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

    /**
     * 
     */
    private static final long serialVersionUID = 1L;
    private JPanel jp;
    private JButton jb;
    private JLabel title;
    private JLabel text;
    private JProgressBar bar;
    private JPanel minPanel;
    private Model model;

    public SimpleGUI() {
        this.setSize((int) (getToolkit().getScreenSize().width * 0.5),
                (int) (getToolkit().getScreenSize().height * 0.5));
        this.model = new ModelImpl();
        BorderLayout bl1 = new BorderLayout();
        this.jp = new JPanel(bl1);
        this.jb = new JButton("Ricarica caffè");
        this.title = new JLabel("Coffee Machine", SwingConstants.CENTER);
        this.text = new JLabel("Testo", SwingConstants.CENTER);
        this.text.setFont(new Font("Helvetica", Font.TYPE1_FONT, 20));
        this.title.setFont(new Font("Helvetica", Font.BOLD, 32));
        this.title.setForeground(Color.BLUE);
        this.bar = new JProgressBar();
        this.bar.setSize((int) (this.getSize().width * 0.7), (int) (this.getSize().height * 0.1));
        this.bar.setValue(25);

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
            text.setText("Stiamo ricaricando la macchina");
        });
    }
    
    public static void main(String[] args){
        new SimpleGUI();
    }
}
