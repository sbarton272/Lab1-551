package com.spencerbarton.lab1_551;

import android.content.Intent;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

import org.opencv.android.BaseLoaderCallback;
import org.opencv.android.InstallCallbackInterface;
import org.opencv.android.LoaderCallbackInterface;
import org.opencv.android.OpenCVLoader;
import org.opencv.core.Mat;


public class MainActivity extends ActionBarActivity implements LoaderCallbackInterface {

    private static final String TAG = "MainActivity";

    protected BaseLoaderCallback mOpenCVCallBack = new BaseLoaderCallback(this) {
        @Override
        public void onManagerConnected(int status) {
            switch (status) {
                case LoaderCallbackInterface.SUCCESS:
                {
                    onOpenCVReady();
                } break;
                default:
                {
                    super.onManagerConnected(status);
                } break;
            }
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    @Override
    protected void onResume()
    {
        super.onResume();

        Log.i("DEMO", "Trying to load OpenCV library");
        if (!OpenCVLoader.initAsync(OpenCVLoader.OPENCV_VERSION_2_4_6, this, mOpenCVCallBack))
        {
            Log.e("DEMO", "Cannot connect to OpenCV Manager");
        }
    }

    protected void onOpenCVReady(){
        //this should crash if opencv is not loaded
        Mat img = new Mat();
        Toast.makeText(getApplicationContext(), "opencv ready", Toast.LENGTH_LONG).show();

    }

    @Override
    public void onManagerConnected(int status) {
        // TODO Auto-generated method stub

    }

    @Override
    public void onPackageInstall(int operation,
                                 InstallCallbackInterface callback) {
        // TODO Auto-generated method stub

    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        Intent intent;
        switch (id) {
            case R.id.action_audio:
                intent = new Intent(this, AudioProcessingActivity.class);
                startActivity(intent);
                return true;
            case R.id.action_image:
                intent = new Intent(this, ImageProcessingActivity.class);
                startActivity(intent);
                return true;
        }
        return super.onOptionsItemSelected(item);
    }
}
