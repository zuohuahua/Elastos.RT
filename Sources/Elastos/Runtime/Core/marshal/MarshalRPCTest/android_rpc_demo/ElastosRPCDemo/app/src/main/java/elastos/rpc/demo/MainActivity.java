package elastos.rpc.demo;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.os.Environment;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import java.net.InetAddress;
import java.net.NetworkInterface;
import java.net.SocketException;
import java.util.ArrayList;
import java.util.Enumeration;
import java.util.List;

public class MainActivity extends Activity implements View.OnClickListener, CheckBox.OnCheckedChangeListener , TestUtils.CarrierNodeListener{
    private static final String TAG = "ElastosRPCDemo";
    private EditText mServerIP = null;
    private  EditText mSettag = null;
    private Button mBtnConnect = null;
    private CheckBox mCheckServer = null;
    private TextView mLocalIpAddress = null;
    private TextView mConnectedState = null;
    private Boolean mConnectedFlag = false;
    private ListView mListView;
    private List<Msg> msgList = new ArrayList<Msg>();
    private MsgAdapter msgAdapter;
    private boolean carrierIsReady = false;

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
                case STATEMSG.RECEIVEMSG: {
                    String message = (String)msg.obj;
                    Log.d(TAG, "[handleMessage] ============================ RECEIVEMSG, message="+message);
                    ReceiveMsg(message);
                }
                case STATEMSG.CARRIERREADY: {
                    carrierIsReady = true;
                    CarrierIsReady();
                }
                default: {
                    Log.d(TAG, "error ============================ ");
                }
            }
        }
    };

    private void CarrierIsReady() {
        if (carrierIsReady) {
            ((TextView)findViewById(R.id.CarrierState)).setTextColor(STATECOLOR.GREEN);
            ((TextView)findViewById(R.id.CarrierState)).setText("CarrierIsReady");
            ((Button)findViewById(R.id.addFriend)).setEnabled(true);
            ((Button)findViewById(R.id.btn_send)).setEnabled(true);
        }
        else {
            ((TextView)findViewById(R.id.CarrierState)).setTextColor(STATECOLOR.RED);
            ((Button)findViewById(R.id.addFriend)).setEnabled(false);
            ((Button)findViewById(R.id.btn_send)).setEnabled(false);
        }
    }

    static {
        System.loadLibrary("log");
        System.loadLibrary("elacommon");
        System.loadLibrary("elasession");
        System.loadLibrary("elacarrier");
        System.loadLibrary("Elastos.Runtime");
        System.loadLibrary("Elastos.CoreLibrary");
        System.loadLibrary("Elastos.RpcDemoClient");
        System.loadLibrary("eladroidrpc");
    }

    @Override
    public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
        if (isChecked) {
            findViewById(R.id.addressContainer).setVisibility(View.GONE);
            mSettag.setVisibility(View.VISIBLE);
            mBtnConnect.setText("Create the Server");
        }
        else {
            findViewById(R.id.addressContainer).setVisibility(View.VISIBLE);
            mSettag.setVisibility(View.GONE);
            mBtnConnect.setText("Connect the Server");
        }
    }

    public native void nativeInitRpcClient();
    public native void nativeInitCarrierNodeListener();
    @Override
    public void OnConnectionStatus(int status) {
        if (status == 1) {
            Log.d(TAG, "[Java] OnConnectionStatus ============================[Connect]");
        }
        else {
            Log.d(TAG, "[Java] OnConnectionStatus ============================[DisConnect]");
        }
    }

    @Override
    public void OnReady() {
        Log.d(TAG, "[Java] OnReady ============================ ");
        Message message = new Message();
        message.what = STATEMSG.CARRIERREADY;
        mHandler.sendMessage(message);
    }

    @Override
    public void OnFriendConnection(String friendid, int status) {
        Log.d(TAG, "[Java] OnFriendConnection ============================friendid=["+friendid+"], status="+status);
    }

    @Override
    public void OnFriendRequest(String userid, String hello) {
        Log.d(TAG, "[Java] OnFriendRequest ============================userid=["+userid+"], hello=["+hello+"]");
    }

    @Override
    public void OnFreindAdded(String userid) {
        Log.d(TAG, "[Java] OnFreindAdded ============================userid=["+userid+"]");
    }

    @Override
    public void OnFriendMessage(String from, String msg) {
        Log.d(TAG, "[Java] OnFriendMessage ============================msg=["+msg+"]");
        Message message = new Message();
        message.what = STATEMSG.RECEIVEMSG;
        message.obj = msg;
        mHandler.sendMessage(message);
    }

    private class STATEMSG {
        public static final int UNCONNECTED = 0;
        public static final int CONNECTED = 1;
        public static final int RECEIVEMSG = 2;
        public static final int CARRIERREADY = 3;
    }

    private class STATECOLOR {
        public static final int RED = 0xFFFF0000;
        public static final int GREEN = 0xFF00FF00;
        public static final int BLUE = 0xFF0000FF;
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        getWindow().setSoftInputMode(WindowManager.LayoutParams.SOFT_INPUT_STATE_ALWAYS_HIDDEN);

        Init();
    }

    private void UpdateStateView(Boolean connected) {
        if (connected) {
            mConnectedFlag = true;
            if (mCheckServer.isChecked()) {
                mConnectedState.setText("Created");
            }
            else {
                mConnectedState.setText("Connected");
            }
            mConnectedState.setTextColor(STATECOLOR.GREEN);

            //Hide some views
            findViewById(R.id.rl_layout_hide).setVisibility(View.GONE);
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
        nativeInitRpcClient();
        nativeInitCarrierNodeListener();

        mServerIP = (EditText)findViewById(R.id.serverip);
        mSettag = (EditText)findViewById(R.id.sendmsg);
        mBtnConnect = (Button)findViewById(R.id.btnConnect);
        mBtnConnect.setOnClickListener(this);
        ((Button)findViewById(R.id.addFriend)).setOnClickListener(this);
        mCheckServer = (CheckBox)findViewById(R.id.checkIsServer);
        mCheckServer.setOnCheckedChangeListener(this);
        mLocalIpAddress = (TextView)findViewById(R.id.localIpAddressText);
        mConnectedState = (TextView)findViewById(R.id.connectState);
        mListView = (ListView) findViewById(R.id.listview);

        mLocalIpAddress.setText("Local Address: [ " + getLocalIpAddress() + " ]");

        ((Button)findViewById(R.id.btn_send)).setOnClickListener(this);
        msgAdapter  = new MsgAdapter(this, R.layout.itemlayout, msgList);
        mListView.setAdapter(msgAdapter);

        CarrierIsReady();
    }

    @Override
    public void onClick(View v) {
        int id = v.getId();
        if (id == R.id.btnConnect) {
            Log.d(TAG, "data path=============="+ Environment.getDataDirectory().getPath());
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
        else if (id == R.id.addFriend) {
            //show the address from carrier
            ((TextView)findViewById(R.id.selfaddresstext)).setText("Self Address: " + TestUtils.GetAddress(true));
//            ((TextView)findViewById(R.id.otheraddresstext)).setText("Other Address: " + TestUtils.GetAddress(false));

            ((TextView)findViewById(R.id.otheraddresstext)).setText("Other Userid: " + TestUtils.GetFriendUserId());
            Boolean isServer = mCheckServer.isChecked();
            if (!isServer) {
                String serverAddr = TestUtils.GetAddress(false);
                TestUtils.AddFriend(serverAddr, "ElastosRPCDemo AddFriend hello");
            }
        }
        else if (id == R.id.btn_send) {
            String message = ((EditText)findViewById(R.id.et_sendmessage)).getText().toString();
            if(!"".equals(message)) {
                SendMsg(message);
            }
            else {
                Toast.makeText(MainActivity.this, "input can't be empty", Toast.LENGTH_SHORT).show();
            }
            ((EditText)findViewById(R.id.et_sendmessage)).setText("");
        }
    }

    private void ReceiveMsg(String message) {
        Msg msg = new Msg(message, Msg.MSG_RECEIVE);
        msgList.add(msg);
        msgAdapter.notifyDataSetChanged();//当有新消息时刷新
        mListView.setSelection(msgList.size());
    }

    private void SendMsg(String message) {
        Msg msg = new Msg(message, Msg.MSG_SEND);
        msgList.add(msg);
        msgAdapter.notifyDataSetChanged();//当有新消息时刷新
        mListView.setSelection(msgList.size());

        //Send message
        TestUtils.SendMsg(message);
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


    public class Msg {
        public static final int MSG_RECEIVE = 0;
        public static final int MSG_SEND = 1;

        private int type;
        private String content;

        public Msg(String content, int type) {
            this.content = content;
            this.type = type;
        }

        public String getMessage() {
            return content;
        }
        public int getType() {
            return type;
        }
    }

    public class MsgAdapter extends ArrayAdapter<Msg> {
        private int resourceID;

        public MsgAdapter(Context context, int resource, List<Msg> objects) {
            super(context, resource, objects);
            resourceID = resource;
        }

        @Override
        public View getView(int position, View convertView, ViewGroup parent) {
            Msg msg = getItem(position);
            View view;
            ViewHolder viewHolder;
            if(convertView == null) {
                view = LayoutInflater.from(getContext()).inflate(resourceID,  null);
                viewHolder = new ViewHolder();
                viewHolder.leftLayout = (LinearLayout)view.findViewById(R.id.left_layout);
                viewHolder.rightLayout = (LinearLayout) view.findViewById(R.id.right_layout);
                viewHolder.leftMsg = (TextView) view.findViewById(R.id.left_msg);
                viewHolder.leftMsg.setTextColor(STATECOLOR.BLUE);

                viewHolder.rightMsg = (TextView) view.findViewById(R.id.right_msg);
                viewHolder.rightMsg.setTextColor(STATECOLOR.GREEN);
                view.setTag(viewHolder);
            }
            else {
                view = convertView;
                viewHolder = (ViewHolder) view.getTag();
            }

            if(msg.getType() == Msg.MSG_RECEIVE) {
                viewHolder.leftLayout.setVisibility(View.VISIBLE);
                viewHolder.rightLayout.setVisibility(View.GONE);
                viewHolder.leftMsg.setText(msg.getMessage());
            }
            else {
                viewHolder.rightLayout.setVisibility(View.VISIBLE);
                viewHolder.leftLayout.setVisibility(View.GONE);
                viewHolder.rightMsg.setText(msg.getMessage());
            }
            return view;
        }

        class ViewHolder {
            LinearLayout leftLayout;
            LinearLayout rightLayout;
            TextView leftMsg;
            TextView rightMsg;
        }
    }
}
