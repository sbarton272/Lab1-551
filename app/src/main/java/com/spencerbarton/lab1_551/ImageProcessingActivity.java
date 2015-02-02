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

import org.opencv.android.Utils;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import org.opencv.core.Scalar;
import org.opencv.core.Size;
import org.opencv.imgproc.Imgproc;


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
        ImageView v = (ImageView) findViewById(R.id.process_img);
        v.setImageResource(R.drawable.team);
    }


    public void onBlur(View view) {
        Log.d(TAG, "Blur");
        Mat ImageMat = getMat();

        Imgproc.blur(ImageMat, ImageMat, new Size(100, 100));

        setMat(ImageMat);
        System.gc();
    }


    public void onCanny(View view) {
        Log.d(TAG, "Canny");

        Mat ImageMat = getMat();

        Imgproc.Canny(ImageMat, ImageMat, 300, 600, 5, true);

        setMat(ImageMat);
        System.gc();
    }

    private Mat getMat() {
        ImageView v = (ImageView) findViewById(R.id.process_img);
        Bitmap bitmap = ((BitmapDrawable)v.getDrawable()).getBitmap();
        //First convert Bitmap to Mat
        Mat ImageMat = new Mat ( bitmap.getHeight(), bitmap.getWidth(), CvType.CV_8U, new Scalar(4));
        Bitmap myBitmap32 = bitmap.copy(Bitmap.Config.ARGB_8888, true);
        Utils.bitmapToMat(myBitmap32, ImageMat);

        return ImageMat;
    }

    private void setMat(Mat ImageMat) {
        ImageView v = (ImageView) findViewById(R.id.process_img);

        //Then convert the processed Mat to Bitmap
        Bitmap resultBitmap = Bitmap.createBitmap(ImageMat.cols(),  ImageMat.rows(),Bitmap.Config.ARGB_8888);
        Utils.matToBitmap(ImageMat, resultBitmap);

        //Set member to the Result Bitmap. This member is displayed in an ImageView
        v.setImageBitmap(resultBitmap);
    }
}
