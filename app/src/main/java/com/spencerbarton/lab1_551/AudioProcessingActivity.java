package com.spencerbarton.lab1_551;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.media.AudioManager;
import android.os.IBinder;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;


/*
    TODO Play audio
    TODO Play two different files
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

    public final static String EXTRA_AUDIO = "com.spencerbarton.lab1_551.EXTRA_AUDIO";
    private PlayAudio mService;
    private boolean mBound = false;
    private ServiceConnection mConnection = new ServiceConnection() {
        @Override
        public void onServiceConnected(ComponentName name, IBinder service) {
            PlayAudio.PlayAudioBinder binder = (PlayAudio.PlayAudioBinder) service;
            mService = binder.getService();
            mBound = true;
        }

        @Override
        public void onServiceDisconnected(ComponentName name) {
            mBound = false;
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_audio_processing);

        // Setup audio to be controlled by the user
        setVolumeControlStream(AudioManager.STREAM_MUSIC);
    }

    @Override
    protected void onStart() {
        super.onStart();

        // Bind audio service
        Intent intent = new Intent(this, PlayAudio.class);
        intent.putExtra(EXTRA_AUDIO, R.raw.test1);
        bindService(intent, mConnection, Context.BIND_AUTO_CREATE);
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_audio_processing, menu);
        return true;
    }

    //---------------------------------------------------------------

    public void playRawAudio(View view) {
        if (mBound) {
            mService.playAudio();
        }
    }

    public void playFilteredAudio(View view) {
        if (mBound) {
            mService.playAudio();
        }
    }

}
