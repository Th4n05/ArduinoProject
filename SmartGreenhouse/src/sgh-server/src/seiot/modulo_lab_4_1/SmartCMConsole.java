package seiot.modulo_lab_4_1;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

import javax.swing.SwingUtilities;

import io.vertx.core.Vertx;

class SmartCMConsole {

    static LogView log = null;

    public static void main(String[] args) throws Exception {

        SwingUtilities.invokeAndWait(() -> {
            log = new LogView();
        });
        String portName = "/dev/cu.usbmodem14201";
        String driver = "com.mysql.jdbc.Driver";
        String dbUri = "jdbc:mysql://127.0.0.0:3306/sgh";
        String userName = "root";
        String password = "";

        Connection connection = null;
        try {
            System.out.println("DataSource.getConnection() driver = " + driver);
            Class.forName(driver);
            System.out.println("DataSource.getConnection() dbUri = " + dbUri);
            connection = DriverManager.getConnection(dbUri, userName, password);
            System.out.println("Connessione stabilita");

        } catch (ClassNotFoundException e) {
            new Exception(e.getMessage());
            System.out.println("Errore" + e.getMessage());
        } catch (SQLException e) {
            new Exception(e.getMessage());
            System.out.println("Errore" + e.getMessage());
        }
        Controller contr = new Controller(portName, /* view, */log, connection);

        Vertx vertx = Vertx.vertx();
        DataService service = new DataService(8080, contr);
        vertx.deployVerticle(service);
        // view.registerController(contr);
        SwingUtilities.invokeLater(() -> {
            // view.setVisible(true);
            log.setVisible(true);
        });
    }
}