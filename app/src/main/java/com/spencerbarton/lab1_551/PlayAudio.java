package com.spencerbarton.lab1_551;

import android.app.Service;
import android.content.Intent;
import android.media.MediaPlayer;
import android.os.Binder;
import android.os.IBinder;
import android.util.Log;

public class PlayAudio extends Service {
    private final static String TAG = "PlayAudioService";
    private final IBinder mBinder = new PlayAudioBinder();
    private MediaPlayer mMediaPlayer;

    @Override
    public IBinder onBind(Intent intent) {
        initAudio(intent);
        return mBinder;
    }

    @Override
    public void onDestroy() {
        stopAudio();
    }

    public void playAudio() {
        try {
            mMediaPlayer.start();
        } catch (IllegalStateException e) {
            Log.e(TAG, e.getMessage());
        }
    }

    public void stopAudio() {
        if (mMediaPlayer != null) {
            mMediaPlayer.stop();
            mMediaPlayer.release();
            mMediaPlayer = null;
        }
    }

    public class PlayAudioBinder extends Binder {

        PlayAudio getService() { return PlayAudio.this; }

    }

    private void initAudio(Intent intent) {
        int audioFile = intent.getIntExtra(AudioProcessingActivity.EXTRA_AUDIO, 0);
        mMediaPlayer = MediaPlayer.create(this, audioFile);

        // Register termination
        mMediaPlayer.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
            @Override
            public void onCompletion(MediaPlayer mediaPlayer) {
                stopAudio();
            }
        });
    }

}