/*
 * Copyright (C) 2021-2021 QuasarApp.
 * Distributed under the lgplv3 software license, see the accompanying
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
*/


package com.quasarapp.androidtools;

import android.app.Activity;
import com.quasarapp.androidtools.IProvider;

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


public class BillingProcessor extends IProvider {

    public BillingProcessor(Activity activityContext,
    ArrayList<String> subs, ArrayList<String> inapp) {
        super(activityContext)
        subsItems = subs;
        inapItems = inapp;
    }

    public void initBilling() {
        billingClient = BillingClient.newBuilder(getActivity()).setListener(new PurchasesUpdatedListener() {
            @Override
            public void onPurchasesUpdated(BillingResult billingResult, List<Purchase> purchases) {
                workWithIncomingData(billingResult, purchases);
            }
        }).enablePendingPurchases().build();

        billingClient.startConnection(new BillingClientStateListener() {
            @Override
            public void onBillingServiceDisconnected() {
                //you can restart your client here.
            }

            @Override
            public void onBillingSetupFinished(BillingResult billingResult) {
                if (billingResult.getResponseCode() == BillingClient.BillingResponseCode.OK){
                    //here billing Client is ready to be used.

                    querySkuDetails();
                }
            }
        });
    }

    private void querySkuSubsDetails() {
        // subs

        SkuDetailsParams.Builder skuDetailsParamsBuilder
                = SkuDetailsParams.newBuilder();

        skuDetailsParamsBuilder.setSkusList(subsItems);
        skuDetailsParamsBuilder.setType(BillingClient.SkuType.SUBS);

        billingClient.querySkuDetailsAsync(skuDetailsParamsBuilder.build(), new SkuDetailsResponseListener() {
                    @Override
                    public void onSkuDetailsResponse(BillingResult billingResult, List<SkuDetails> skuDetailsList) {

                        if (billingResult.getResponseCode() == BillingClient.BillingResponseCode.OK){

                            for (SkuDetails skuDetails : skuDetailsList) {
                                mSkuDetailsMap.put(skuDetails.getSku(), skuDetails);
                            }

                            RestoringPurchases();
                        }
                    }
                });
    }

    private void querySkuInappDetails() {

        SkuDetailsParams.Builder skuDetailsParamsBuilder
                = SkuDetailsParams.newBuilder();

        skuDetailsParamsBuilder.setSkusList(inapItems);
        skuDetailsParamsBuilder.setType(BillingClient.SkuType.INAPP);

        billingClient.querySkuDetailsAsync(skuDetailsParamsBuilder.build(), new SkuDetailsResponseListener() {
                    @Override
                    public void onSkuDetailsResponse(BillingResult billingResult, List<SkuDetails> skuDetailsList) {

                        if (billingResult.getResponseCode() == BillingClient.BillingResponseCode.OK){

                            for (SkuDetails skuDetails : skuDetailsList) {
                                mSkuDetailsMap.put(skuDetails.getSku(), skuDetails);
                            }
                        }
                    }
                });
    }

    public void startPurchase(String item) {

        if (mSkuDetailsMap.size() > 0) {

            BillingFlowParams billingFlowParams = BillingFlowParams.newBuilder()
                    .setSkuDetails(mSkuDetailsMap.get(item))
                    .build();

            billingClient.launchBillingFlow(getActivity(), billingFlowParams);
        }
    }

    protected void RestoringPurchases(){
        //To Query you have to provide skuType which is "BillingClient.SkuType.INAPP" or "BillingClient.SkuType.SUBS"
        billingClient.queryPurchasesAsync(BillingClient.SkuType.SUBS,
        new PurchasesResponseListener() {
            @Override
            public void onQueryPurchasesResponse(BillingResult billingResult,
                                                 List<Purchase> purchases) {
                //here you can process your purchases.
                workWithIncomingData(billingResult, purchases);
            }
        });
    }

    private void workWithIncomingData(BillingResult billingResult, List<Purchase> purchases) {
        if (billingResult.getResponseCode() == BillingClient.BillingResponseCode.OK) {

            //here you can process the new purchases.
            for (Purchase purchase : purchases) {

                if (purchase.getPurchaseState() == PurchaseState.UNSPECIFIED_STATE) {
                    System.out.println("failed to check realy state of purchase");
                    continue;
                }

                if (purchase.getPurchaseState() == PurchaseState.PENDING) {
                    System.out.println("purchase still pending");
                    continue;
                }

                if (getProvider() != null) {
                    ArrayList<String> list = purchase.getSkus();
                    for (String id : list) {
                        getProvider().sendPurchaseToApp(id ,purchase.getPurchaseToken(), purchase.getQuantity());
                    }
                }
            }
        }
    }

    private Map<String, SkuDetails> mSkuDetailsMap = new HashMap<>();

    private BillingClient billingClient;
    
    private ArrayList<String> subsItems;
    private ArrayList<String> inapItems;
}
