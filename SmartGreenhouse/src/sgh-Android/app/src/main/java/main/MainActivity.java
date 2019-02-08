package main;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.SeekBar;
import android.widget.Switch;
import android.widget.TextView;
import com.example.thanos.mobile_app.R;
import btlib.*;
import utils.*;
import exceptions.*;
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

        final Switch s = (Switch) findViewById(R.id.switchPompa);
        s.setText("Pompa chiusa");

        final SeekBar sk = findViewById(R.id.seekLiter);
        sk.setMax(150);
       // sk.setEnabled(false);
        s.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if (isChecked) {
                    s.setText("Pompa aperta");
                    sk.setEnabled(true);
                    if (btChannel != null) {
                        btChannel.sendMessage("APERTA");
                    }
                } else {
                    s.setText("Pompa chiusa");
                    sk.setEnabled(false);
                    if (btChannel != null) {
                        btChannel.sendMessage("CHIUSA");
                    }
                }
            }
        });


       sk.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                int MIN = 0;
                if (progress >= MIN) {
                    ((TextView) findViewById(R.id.seekLabel)).setText(" Litri al minuto impostati:  \t" + progress);

                }
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                if (s.isChecked() && btChannel!= null){
                    btChannel.sendMessage(String.valueOf(seekBar.getProgress()));
                }
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
                         ((TextView) findViewById(R.id.humidityLabel)).setText(String.format("Umidità rilevata:  %s \n", receivedMessage));

                    }


                    @Override
                    public void onMessageSent(String sentMessage) { }
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
