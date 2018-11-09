package seiot.modulo_lab_2_2.msg;

import seiot.modulo_lab_2_2.msg.CommChannel;
import seiot.modulo_lab_2_2.msg.jssc.*;

class ModelImpl implements Model {

    private CommChannel channel;

    public void connectArduino() throws Exception {
        channel = new SerialCommChannel("/dev/cu.usbmodem1411", 9600);
        /* attesa necessaria per fare in modo che Arduino completi il reboot */
        System.out.println("Waiting Arduino for rebooting...");
        Thread.sleep(4000);
        System.out.println("Ready.");
    }

    public void comunication() throws Exception {
        while (true) {
            System.out.println("Sending ping");
            channel.sendMsg("ping");
            String msg = channel.receiveMsg();
            System.out.println("Received: " + msg);
            Thread.sleep(500);
        }
    }

}
