package com.quasarapp.androidtools;

import android.app.Activity;
import androidx.core.content.ContextCompat
import com.quasarapp.androidtools.IProvider;

public class AndroidUtils extends IProvider {
    public AndroidUtils(Activity activityContext) {
        super(activityContext);
    }

    public boolean addPermision(String permision) {

        if (ContextCompat.checkSelfPermission(getActivity(), permision) != PackageManager.PERMISSION_GRANTED) {

            int requestCode = 112;
            ActivityCompat.requestPermissions(getActivity(), new String[]{permision}, requestCode);
        }

        return true;
    }
}
