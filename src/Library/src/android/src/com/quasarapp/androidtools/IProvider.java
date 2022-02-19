package com.quasarapp.androidtools;

import android.app.Activity;
import com.quasarapp.androidtools.CppProvider;

public class IProvider {
    public AndroidUtils(Activity activityContext) {
        m_acrivityContext = activityContext;
    }

    public void setCppProvider(CppProvider provider) {
        m_provider = provider;
    }

    public Activity getActivity() {
        return m_acrivityContext;
    }

    public CppProvider getProvider() {
        return m_provider;
    }

private Activity m_acrivityContext;
private CppProvider m_provider;

}
