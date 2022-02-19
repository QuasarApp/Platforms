/*
 * Copyright (C) 2021-2021 QuasarApp.
 * Distributed under the lgplv3 software license, see the accompanying
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
*/


package com.quasarapp.androidtools;

import android.app.Activity;
import com.quasarapp.androidtools.IProvider;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class ScreenController extends IProvider {

    public ScreenController(Activity activityContext) {
        super(activityContext);
    }

    // see google docs https://developer.android.com/reference/android/view/Window
    public void clearWindowFlagAsync(int flag) {
        
        if (getActivity() == null)
            return;

        //perform heavy task here and finally update the UI with result this way -
        getActivity().runOnUiThread(new Runnable() {
            @Override
            public void run() {
                Window decorView = getWindow();
                decorView.clearFlags(flag);
            }
        });
    }

    public void addWindowFlagAsync(int flag) {

        if (getActivity() == null)
            return;
            
        //perform heavy task here and finally update the UI with result this way -
        getActivity().runOnUiThread(new Runnable() {
            @Override
            public void run() {
                Window decorView = getWindow();
                decorView.addFlags(flag);
            }
        });
    }

}
