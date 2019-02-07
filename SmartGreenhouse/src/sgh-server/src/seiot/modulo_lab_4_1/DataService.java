package seiot.modulo_lab_4_1;

import io.vertx.core.AbstractVerticle;
import io.vertx.core.Vertx;
import io.vertx.core.http.HttpServerResponse;
import io.vertx.core.json.JsonArray;
import io.vertx.core.json.JsonObject;
import io.vertx.ext.web.Router;
import io.vertx.ext.web.RoutingContext;
import io.vertx.ext.web.handler.BodyHandler;
import seiot.modulo_lab_2_2.msg.jssc.SerialCommChannel;
import java.sql.*;
import java.util.Calendar;
import java.util.Date;
import java.util.LinkedList;

/*
 * Data Service as a vertx event-loop 
 */
public class DataService extends AbstractVerticle {

    private int port;
    private static final int MAX_SIZE = 10;
    static LogView logger = null;

    private String myDriver;
    private String myUrl;
    private Connection conn;

    private LinkedList<DataPoint> values;
    //private static SerialCommChannel channel;

    public DataService(int port) throws Exception {
        values = new LinkedList<>();
        this.port = port;
        //channel = new SerialCommChannel("/dev/cu.usbmodem14101", 9600);
        myDriver = "org.gjt.mm.mysql.Driver";
        myUrl = "jdbc:mysql://localhost/sgh";
        Class.forName(myDriver);
        conn = DriverManager.getConnection(myUrl, "root", "");
    }

    @Override
    public void start() throws InterruptedException {
        Router router = Router.router(vertx);
        router.route().handler(BodyHandler.create());
        router.post("/api/data").handler(this::handleAddNewData);
        router.get("/api/data").handler(this::handleGetData);
        vertx.createHttpServer().requestHandler(router::accept).listen(port);
        /*System.out.println("Waiting Arduino for rebooting...");
        System.out.println("Ready.");
        logger = new LogView();
        logger.setVisible(true);*/

        log("Service ready.");
    }

    private void handleAddNewData(RoutingContext routingContext) {
        HttpServerResponse response = routingContext.response();
        // log("new msg "+routingContext.getBodyAsString());
        JsonObject res = routingContext.getBodyAsJson();
        if (res == null) {
            sendError(400, response);
        } else {
            float value = res.getFloat("value");
            String place = res.getString("place");
            long time = System.currentTimeMillis();

            values.addFirst(new DataPoint(value, time, place));
            if (values.size() > MAX_SIZE) {
                values.removeLast();
            }

            log("Humidity: " + value + "% from " + place + " on " + new Date(time));
            try {
                // the mysql insert statement
                String query = " insert into dati (type, value, time)" + " values ( ?, ?, ?)";

                // create the mysql insert preparedstatement
                PreparedStatement preparedStmt = conn.prepareStatement(query);
                preparedStmt.setString(1, "H");
                preparedStmt.setFloat(2, value);
                preparedStmt.setDate(3, (java.sql.Date) new Date(time));

                // execute the preparedstatement
                preparedStmt.execute();

                conn.close();
            } catch (Exception e) {
                System.err.println("Got an exception!");
                System.err.println(e.getMessage());
            }
            /*try {
                channel.sendMsg(String.valueOf(value));
            } catch (Exception e1) {
                e1.printStackTrace();
            }*/
            response.setStatusCode(200).end();
        }
    }

    private void handleGetData(RoutingContext routingContext) {
        JsonArray arr = new JsonArray();
        for (DataPoint p : values) {
            JsonObject data = new JsonObject();
            data.put("time", p.getTime());
            data.put("value", p.getValue());
            data.put("place", p.getPlace());
            arr.add(data);
        }
        routingContext.response().putHeader("content-type", "application/json").end(arr.encodePrettily());
    }

    private void sendError(int statusCode, HttpServerResponse response) {
        response.setStatusCode(statusCode).end();
    }

    private void log(String msg) {
        System.out.println("[DATA SERVICE] " + msg);
    }

    public static void main(String[] args) throws Exception {
        Vertx vertx = Vertx.vertx();
        DataService service = new DataService(8000);
        vertx.deployVerticle(service);
        //Thread.sleep(1000);
        /*
         * while (true){ try { String msg = channel.receiveMsg(); logger.log(msg); }
         * catch (Exception ex){ ex.printStackTrace(); } }
         */
    }
}