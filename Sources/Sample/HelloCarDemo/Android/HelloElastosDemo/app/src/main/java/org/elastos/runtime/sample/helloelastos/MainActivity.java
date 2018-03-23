package org.elastos.runtime.sample.helloelastos;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //Show the string that comes from a Elastos car objects[CHelloCar]
        TextView textLabel = (TextView)findViewById(R.id.label);
        TestUtils tu = new TestUtils();
        String helloString = tu.getHelloCarString();
        textLabel.setText(helloString);
    }
}
