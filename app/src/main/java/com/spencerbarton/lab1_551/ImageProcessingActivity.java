package com.spencerbarton.lab1_551;

import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.Matrix;
import android.graphics.drawable.BitmapDrawable;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ImageView;

import org.opencv.core.Mat;


public class ImageProcessingActivity extends ActionBarActivity {

    private static final String TAG = "ImageProcessingActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_image_processing);
        Intent intent = getIntent();
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
//        getMenuInflater().inflate(R.menu.menu_image_processing, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    public void onReset(View view) {
        Log.d(TAG, "Reset");
        ImageView v = (ImageView) findViewById(R.id.unprocessed_img);
        v.setImageResource(R.drawable.team);
    }


    public void onBlur(View view) {
        Log.d(TAG, "Blur");
        Bitmap bitmap = ((BitmapDrawable)v.getDrawable()).getBitmap();
    }


    public void onCanny(View view) {
        Log.d(TAG, "Canny");
    }
}
