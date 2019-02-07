package seiot.modulo_lab_4_1;

import java.sql.*;
import java.util.Calendar;
import seiot.modulo_lab_2_2.msg.jssc.*;

public class MonitoringAgent extends Thread {

    SerialCommChannel channel;
    LogView logger;
    Connection conn;

    static final String IRR_PREFIX = "ir:";
    static final String LOG_PREFIX = "lo:";
    static final String ERROR_PREFIX = "er:";
    /*
     * static final String MSG_WELCOME = "we"; static final String MSG_SLEEPING =
     * "zz"; static final String MSG_READY = "ok"; static final String
     * MSG_MAKING_COFFEE = "mc"; static final String MSG_COFFEE_READY = "re"; static
     * final String MSG_SUGAR_LEVEL = "s|"; static final String MSG_REFILLED = "f|";
     * static final String MSG_MAINTENANCE = "ma";
     */

    public MonitoringAgent(SerialCommChannel channel, /* SmartCMView view, */ LogView log, Connection conn)
            throws Exception {
        this.logger = log;
        this.channel = channel;
        this.conn = conn;
    }

    public void run() {
        while (true) {
            try {
                String msg = channel.receiveMsg();
                if (msg.startsWith(IRR_PREFIX)) {
                    String time = msg.substring(IRR_PREFIX.length());
                    try {
                        Calendar calendar = Calendar.getInstance();
                        java.sql.Date startDate = new java.sql.Date(calendar.getTime().getTime());
                        Timestamp timestamp = new Timestamp(startDate.getTime());

                        // the mysql insert statement
                        String query = " insert into dati (type, value, time)" + " values ( ?, ?, ?)";

                        // create the mysql insert preparedstatement
                        PreparedStatement preparedStmt = conn.prepareStatement(query);
                        preparedStmt.setString(1, "I");
                        preparedStmt.setString(2, time);
                        preparedStmt.setTimestamp(3, timestamp);

                        // execute the preparedstatement
                        preparedStmt.execute();

                    } catch (Exception e) {
                        System.out.println(e);
                    }
                } else if (msg.startsWith(LOG_PREFIX)) {
                    this.logger.log(msg.substring(LOG_PREFIX.length()));
                } else if (msg.startsWith(ERROR_PREFIX)) {
                    String segnalation = msg.substring(ERROR_PREFIX.length());
                    try {
                        Calendar calendar = Calendar.getInstance();
                        java.sql.Date startDate = new java.sql.Date(calendar.getTime().getTime());
                        Timestamp timestamp = new Timestamp(startDate.getTime());

                        // the mysql insert statement
                        String query = " insert into dati (type, value, time)" + " values ( ?, ?, ?)";

                        // create the mysql insert preparedstatement
                        PreparedStatement preparedStmt = conn.prepareStatement(query);
                        preparedStmt.setString(1, "E");
                        preparedStmt.setString(2, segnalation);
                        preparedStmt.setTimestamp(3, timestamp);

                        // execute the preparedstatement
                        preparedStmt.execute();

                    } catch (Exception e) {
                        System.out.println(e);
                    }
                }
            } catch (Exception ex) {
                ex.printStackTrace();
            }
        }
    }

}
