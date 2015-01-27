package com.spencerbarton.lab1_551;

import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;


/*
    TODO Play audio
    TODO Load from SD card
In this activity, you will design a user interface to load, process and playback audio files from the
SD card. You will interface with the C code that you wrote in HW1 (using the NDK) to process
this audio signal.
1. You will denoise the tone as you did in HW1 and play it back
2. You will modulate the tone using a sine wave and play it back.
Because of the moderate difficulty of playing back processed audio with Android, you are allowed
to play the resulting .dat files on your computer (again using SoX to convert them back to .wav
files)

 */

public class AudioProcessingActivity extends ActionBarActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_audio_processing);
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_audio_processing, menu);
        return true;
    }

}
