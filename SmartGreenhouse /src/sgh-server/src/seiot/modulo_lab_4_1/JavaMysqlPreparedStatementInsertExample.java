package seiot.modulo_lab_4_1;

import java.sql.*;
import java.util.Calendar;
import java.util.Date;

/**
 * A Java MySQL PreparedStatement INSERT example. Demonstrates the use of a SQL
 * INSERT statement against a MySQL database, called from a Java program, using
 * a Java PreparedStatement.
 * 
 * Created by Alvin Alexander, http://alvinalexander.com
 */
public class JavaMysqlPreparedStatementInsertExample {

    public static void main(String[] args) {
        try {
            // create a mysql database connection
            //String myDriver = "com.mysql.jdbc.Driver";
            String myUrl = "jdbc:mysql://localhost/sgh";
            Class.forName("com.mysql.jdbc.Driver").newInstance();
            Connection conn = DriverManager.getConnection(myUrl, "root", "");

            // create a sql date object so we can use it in our INSERT statement
            Calendar calendar = Calendar.getInstance();
            java.sql.Date startDate = new java.sql.Date(calendar.getTime().getTime());

            // the mysql insert statement
            String query = " insert into dati (type, value, time)" + " values ( ?, ?, ?)";

            // create the mysql insert preparedstatement
            PreparedStatement preparedStmt = conn.prepareStatement(query);
            preparedStmt.setString(1, "H");
            preparedStmt.setFloat(2, 50);
            preparedStmt.setDate(3, startDate);

            // execute the preparedstatement
            preparedStmt.execute();

            conn.close();
        } catch (Exception e) {
            //System.err.println("Got an exception!");
            System.out.println(e);
        }
    }
}