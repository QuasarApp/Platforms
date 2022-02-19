//#
//# Copyright (C) 2021-2022 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

package com.quasarapp.androidtools;

import android.app.Activity;
import com.quasarapp.androidtools.BillingProcessor;
import com.quasarapp.androidtools.ScreenController;

public class CppProvider {

public CppProvider() {
    billingProcessor.setCppProvider(this);
    providerContext = this;
}

public void setBillingProcessor(BillingProcessor billing) {
    billingProcessor = billing;
}

public void setScreenController(ScreenController screen) {
    screenController = screen;
}

public void getPremiumP(String id) {
    if (billingProcessor == null) {
        System.out.println("Failed to bye item, please init billingOricessor before use. For initialize billing invoke the setBillingProcessor method.");
        return;
    }
        
    billingProcessor.startPurchase(id);
}

public void sendPurchaseToApp(String id, String token, int quantity) {
    purchaseReceived(id, token, quantity);
}

public void initBillingP() {
    if (billingProcessor == null) {
        System.out.println("Failed to bye item, please init billingOricessor before use. For initialize billing invoke the setBillingProcessor method.");
        return;
    }
        
    billingProcessor.initBilling();
}

// Cpp Code
private static native void purchaseReceived(String id, String token, int quantity);

// Java code
private static void getItem(String id) {
    if (providerContext != null) {
        providerContext.getPremiumP(id);
    }
}

private static void initBilling() {
    if (providerContext != null) {
        providerContext.initBillingP();
    }
}

private static void setWindowFlags(int flag, boolean enable) {
    if (screenController == null) {
        System.out.println("Failed to sets window flag, please init screenController before use. For initialize billing invoke the setScreenController method.");
        return;
    }

    if (enable) {
        screenController.addWindowFlagAsync(flag);
    } else {
        screenController.clearWindowFlagAsync(flag);
    }
}

private BillingProcessor billingProcessor;
private ScreenController screenController;
private static CppProvider providerContext;

}
