package main;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.EditText;
import android.widget.Switch;
import android.widget.TextView;

import com.example.thanos.androidserra.R;
import Utils.*;
import Exception.*;
import java.util.UUID;

public class MainActivity extends AppCompatActivity {

    private BluetoothChannel btChannel;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final BluetoothAdapter btAdapter = BluetoothAdapter.getDefaultAdapter();

        if(btAdapter != null && !btAdapter.isEnabled()){
            startActivityForResult(new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE), C.bluetooth.ENABLE_BT_REQUEST);
        }
        initUI();
    }

    private void initUI() {
        findViewById(R.id.connectBtn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    connectToBTServer();
                } catch (BluetoothDeviceNotFound bluetoothDeviceNotFound) {
                    bluetoothDeviceNotFound.printStackTrace();
                }
            }
        });
        Switch sw = (Switch)findViewById(R.id.switchPompa);
        sw.setTextOn("Aperta");
        sw.setTextOff("Chiusa");

        findViewById(R.id.sendBtn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String message = ((EditText)findViewById(R.id.editText)).getText().toString();
                btChannel.sendMessage(message);
                ((EditText)findViewById(R.id.editText)).setText("");


            }
        });
    }

    private void connectToBTServer() throws BluetoothDeviceNotFound {
        final BluetoothDevice serverDevice = BluetoothUtils.getPairedDeviceByName(C.bluetooth.BT_DEVICE_ACTING_AS_SERVER_NAME);
        final UUID uuid = BluetoothUtils.getEmbeddedDeviceDefaultUuid();

        AsyncTask<Void, Void, Integer> execute = new ConnectToBluetoothServerTask(serverDevice, uuid, new ConnectionTask.EventListener() {
            @Override
            public void onConnectionActive(final BluetoothChannel channel) {

                ((TextView) findViewById(R.id.statusLabel)).setText(String.format("Status : connected to server on device %s",
                        serverDevice.getName()));

                findViewById(R.id.connectBtn).setEnabled(false);

                btChannel = channel;
                btChannel.registerListener(new RealBluetoothChannel.Listener() {
                    @Override
                    public void onMessageReceived(String receivedMessage) {
                       ((TextView) findViewById(R.id.chatLabel)).append(String.format("> [RECEIVED from %s] %s\n",
                                btChannel.getRemoteDeviceName(), receivedMessage));
                        System.out.println(receivedMessage);

                    }


                    @Override
                    public void onMessageSent(String sentMessage) {
                        ((TextView) findViewById(R.id.chatLabel)).append(String.format("> [SENT to %s] %s\n",
                                btChannel.getRemoteDeviceName(), sentMessage));
                    }
                });
                btChannel.sendMessage("CONNESSO");
            }

            @Override
            public void onConnectionCanceled() {
                ((TextView) findViewById(R.id.statusLabel)).setText(String.format("Status : unable to connect, device %s not found!",
                        C.bluetooth.BT_DEVICE_ACTING_AS_SERVER_NAME));
            }
        }).execute();
    }
}
