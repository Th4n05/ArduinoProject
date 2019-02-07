package seiot.modulo_lab_4_1;

import java.sql.*;
import java.util.Calendar;


public class JavaMysqlPreparedStatementInsertExample {
    
    public static void main(String[] args) {
        
        String driver = "com.mysql.jdbc.Driver";
        String dbUri = "jdbc:mysql://127.0.0.0:3306/sgh";
        String userName = "root";
        String password = "";
         
        Connection connection = null;
         try {
             System.out.println("DataSource.getConnection() driver = "+driver);
             Class.forName(driver);
             System.out.println("DataSource.getConnection() dbUri = "+dbUri);
             connection = DriverManager.getConnection(dbUri, userName, password);
             System.out.println("Connessione stabilita");
             
         }
         catch (ClassNotFoundException e) {
             new Exception(e.getMessage());
             System.out.println("Errore"+ e.getMessage());
         }
         catch(SQLException e) {
             new Exception(e.getMessage());
             System.out.println("Errore"+ e.getMessage());
         }

        try {
            Calendar calendar = Calendar.getInstance();
            java.sql.Date startDate = new java.sql.Date(calendar.getTime().getTime());

            // the mysql insert statement
            String query = " insert into dati (type, value, time)" + " values ( ?, ?, ?)";

            // create the mysql insert preparedstatement
            PreparedStatement preparedStmt = connection.prepareStatement(query);
            preparedStmt.setString(1, "H");
            preparedStmt.setFloat(2, 50);
            preparedStmt.setDate(3, startDate);

            // execute the preparedstatement
            System.out.println("va");
            preparedStmt.execute();

            connection.close();
        } catch (Exception e) {
            System.err.println("Got an exception!");
            System.out.println(e);
        }
    }
}