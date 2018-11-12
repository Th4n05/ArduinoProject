package seiot.modulo_lab_2_2.msg;

public interface Model {
    
    void connectArduino() throws Exception;
    
    String receiveStatus() throws Exception;    
    
    void rechargeCoffee(String msg) throws Exception;

    
}
