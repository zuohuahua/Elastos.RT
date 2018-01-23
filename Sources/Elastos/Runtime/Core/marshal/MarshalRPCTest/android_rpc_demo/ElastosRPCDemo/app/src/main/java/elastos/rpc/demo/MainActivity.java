package elastos.rpc.demo;

import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.TextView;

import java.net.InetAddress;
import java.net.NetworkInterface;
import java.net.SocketException;
import java.util.Enumeration;

public class MainActivity extends Activity implements View.OnClickListener, CheckBox.OnCheckedChangeListener {
    private static final String TAG = "ElastosRPCDemo";
    private EditText mServerIP = null;
    private  EditText mSettag = null;
    private Button mBtnConnect = null;
    private Button mBtnTag = null;
    private CheckBox mCheckServer = null;
    private TextView mLocalIpAddress = null;
    private TextView mConnectedState = null;
    private Boolean mConnectedFlag = false;
    private Handler mHandler = new Handler() {
        @Override
        public void handleMessage(Message msg) {
            switch (msg.what) {
                case STATEMSG.CONNECTED: {
                    Log.d(TAG, "[handleMessage] ============================ CONNECTED.");
                    UpdateStateView(true);
                    break;
                }
                case STATEMSG.UNCONNECTED: {
                    Log.d(TAG, "[handleMessage] ============================ UNCONNECTED.");
                    UpdateStateView(false);
                    break;
                }
                case STATEMSG.GETTAG: {
                    String tag = (String)msg.obj;
                    Log.d(TAG, "[handleMessage] ============================ GETTAG.=======tag=" + tag);
                    findViewById(R.id.testTag2).setVisibility(View.VISIBLE);
                    ((TextView)findViewById(R.id.testTag2)).setText(tag);
                    break;
                }
                case STATEMSG.SETTAG: {
                    String tag = (String)msg.obj;
                    Log.d(TAG, "[handleMessage] ============================ SETTAG.=======tag=" + tag);
                    ((TextView)findViewById(R.id.testTag2)).setText("");
                    break;
                }
                default: {
                    Log.d(TAG, "error ============================ ");
                }
            }
        }
    };

    @Override
    public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
        if (isChecked) {
            mBtnTag.setText("SendMsg");
            findViewById(R.id.addressContainer).setVisibility(View.GONE);
            mSettag.setVisibility(View.VISIBLE);
            mBtnConnect.setText("Create the Server");
        }
        else {
            mBtnTag.setText("GetMsg");
            findViewById(R.id.addressContainer).setVisibility(View.VISIBLE);
            mSettag.setVisibility(View.GONE);
            mBtnConnect.setText("Connect the Server");
        }
    }

    private class STATEMSG {
        public static final int UNCONNECTED = 0;
        public static final int CONNECTED = 1;
        public static final int SETTAG = 2;
        public static final int GETTAG = 3;
    }

    private class STATECOLOR {
        public static final int RED = 0xFFFF0000;
        public static final int GREEN = 0xFF00FF00;
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Init();;
    }

    private void UpdateStateView(Boolean state) {
        if (state) {
            mConnectedFlag = true;
            if (mCheckServer.isChecked()) {
                mConnectedState.setText("Created");
            }
            else {
                mConnectedState.setText("Connected");
            }
            mConnectedState.setTextColor(STATECOLOR.GREEN);
        }
        else {
            if (mCheckServer.isChecked()) {
                mConnectedState.setText("Create Fail");
            }
            else {
                mConnectedState.setText("UnConnected");
            }
            mConnectedState.setTextColor(STATECOLOR.RED);
        }
    }

    private void Init() {
        mServerIP = (EditText)findViewById(R.id.serverip);
        mSettag = (EditText)findViewById(R.id.sendmsg);
        mBtnConnect = (Button)findViewById(R.id.btnConnect);
        mBtnTag = (Button)findViewById(R.id.processmsg);
        mBtnConnect.setOnClickListener(this);
        mBtnTag.setOnClickListener(this);
        mCheckServer = (CheckBox)findViewById(R.id.checkIsServer);
        mCheckServer.setOnCheckedChangeListener(this);
        mLocalIpAddress = (TextView)findViewById(R.id.localIpAddressText);
        mConnectedState = (TextView)findViewById(R.id.connectState);

        String localip = getLocalIpAddress();
        mLocalIpAddress.setText("Local Address: [ " + localip + " ]");
    }

    @Override
    public void onClick(View v) {
        int id = v.getId();
        if (id == R.id.processmsg) {
            if (mConnectedFlag) {
                Thread thread = new Thread(new Runnable() {
                    @Override
                    public void run() {
                        String tag;
                        Message message = new Message();
                        if (mCheckServer.isChecked()) {
                            tag = mSettag.getText().toString();
                            TestUtils.SetTag(tag);
                            message.what = STATEMSG.SETTAG;
                        }
                        else {
                            tag = TestUtils.GetTag();
                            message.what = STATEMSG.GETTAG;
                        }

                        message.obj = tag;
                        mHandler.sendMessage(message);
                    }
                });
                thread.start();
            }
        }
        else if (id == R.id.btnConnect) {
            Thread thread = new Thread(new Runnable() {
                @Override
                public void run() {
                    String server = mServerIP.getText().toString();
                    Boolean isServer = mCheckServer.isChecked();
                    Boolean state = false;
                    if (isServer) {
                        state = TestUtils.Connect(getLocalIpAddress(), isServer);
                    }
                    else {
                        state = TestUtils.Connect(server, isServer);
                    }

                    Message message = new Message();
                    message.what = state ? STATEMSG.CONNECTED : STATEMSG.UNCONNECTED;
                    mHandler.sendMessage(message);
                }
            });
            thread.start();
        }
    }

    public static String getLocalIpAddress() {
        try {
            for (Enumeration<NetworkInterface> en = NetworkInterface
                    .getNetworkInterfaces(); en.hasMoreElements();) {
                NetworkInterface intf = en.nextElement();
                for (Enumeration<InetAddress> enumIpAddr = intf
                        .getInetAddresses(); enumIpAddr.hasMoreElements();) {
                    InetAddress inetAddress = enumIpAddr.nextElement();
                    if (!inetAddress.isLoopbackAddress() && !inetAddress.isLinkLocalAddress()) {
                        return inetAddress.getHostAddress().toString();
                    }
                }
            }
        } catch (SocketException ex) {
            Log.e("IpAddress", ex.toString());
        }

        return null;
    }
}
