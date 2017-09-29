package elastos.china.com.eldroidsdksample;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

import elastos.china.com.eldroidsdk.ElDroidOS;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //Show the string that comes from a Elastos car objects[CString]
        TextView view = (TextView)findViewById(R.id.textview);
        String elStr = ElDroidOS.getElastosString();
        view.setText(elStr);
    }
}
