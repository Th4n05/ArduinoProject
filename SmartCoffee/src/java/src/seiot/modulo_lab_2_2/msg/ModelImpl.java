package seiot.modulo_lab_2_2.msg;

import seiot.modulo_lab_2_2.msg.CommChannel;
import seiot.modulo_lab_2_2.msg.jssc.*;

class ModelImpl implements Model {

    private CommChannel channel;

    @Override
    public void connectArduino() throws Exception {
        channel = new SerialCommChannel("/dev/cu.usbmodem1411", 9600);
        /* attesa necessaria per fare in modo che Arduino completi il reboot */
        System.out.println("Waiting Arduino for rebooting...");
        Thread.sleep(4000);
        System.out.println("Ready.");
    }

    @Override
    public String receiveStatus() throws Exception {

        return channel.receiveMsg();

    }

    @Override
    public void rechargeCoffee(String msg) throws Exception {
        channel.sendMsg(msg);
    }

}
