package seiot.modulo_lab_4_1;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import seiot.modulo_lab_2_2.msg.*;
import seiot.modulo_lab_2_2.msg.jssc.*;

public class Controller implements ActionListener {

	static final String MSG_REQUEST_TO_ENTER 	= "1";
	static final String MSG_STOP  				= "2";

	SerialCommChannel channel;
	
	public Controller(String port, LogView logger) throws Exception {
		channel = new SerialCommChannel(port,9600);		
		new MonitoringAgent(channel,logger).start();
			
		/* attesa necessaria per fare in modo che Arduino completi il reboot */
		
		System.out.println("Waiting Arduino for rebooting...");		
		Thread.sleep(4000);
		System.out.println("Ready.");		
	
	}
	
	public void actionPerformed(ActionEvent ev){
		  try {
			  if (ev.getActionCommand().equals("Refill")){
				  channel.sendMsg("10");
			  }
		  } catch (Exception ex){
			  ex.printStackTrace();
		  }
	  }

}
