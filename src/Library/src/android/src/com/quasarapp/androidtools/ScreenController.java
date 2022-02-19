/*
 * Copyright (C) 2021-2021 QuasarApp.
 * Distributed under the lgplv3 software license, see the accompanying
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
*/


package com.quasarapp.androidtools;

import android.app.Activity;

import com.android.billingclient.api.BillingClient;
import com.android.billingclient.api.BillingClientStateListener;
import com.android.billingclient.api.BillingFlowParams;
import com.android.billingclient.api.Purchase;
import com.android.billingclient.api.PurchasesUpdatedListener;
import com.android.billingclient.api.SkuDetails;
import com.android.billingclient.api.SkuDetailsParams;
import com.android.billingclient.api.SkuDetailsResponseListener;
import com.android.billingclient.api.BillingResult;
import com.android.billingclient.api.PurchasesResponseListener;
import com.android.billingclient.api.Purchase.PurchaseState;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class ScreenController {

    public ScreenController(Activity activityContext) {
        m_acrivityContext = activityContext;
    }

    public void setCppProvider(CppProvider provider) {
        m_provider = provider;
    }

    // see google docs https://developer.android.com/reference/android/view/Window
    public void clearWindowFlagAsync(int flag) {
        
        if (m_acrivityContext == null)
            return;

        //perform heavy task here and finally update the UI with result this way -
        m_acrivityContext.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                Window decorView = getWindow();
                decorView.clearFlags(flag);
            }
        });
    }

    public void addWindowFlagAsync(int flag) {

        if (m_acrivityContext == null)
            return;
            
        //perform heavy task here and finally update the UI with result this way -
        m_acrivityContext.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                Window decorView = getWindow();
                decorView.addFlags(flag);
            }
        });
    }


    private Activity m_acrivityContext;
    private CppProvider m_provider;

}
