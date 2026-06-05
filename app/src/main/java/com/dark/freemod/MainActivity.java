package com.dark.freemod;

import android.app.Activity;
import android.os.Bundle;
import android.widget.Toast;

public class MainActivity extends Activity {

    // С++ кітапханасын жүктеу
    static {
        System.loadLibrary("darkinjector");
    }

    // С++ деңгейіндегі RAM-ды басып алу функциясы
    public native boolean attachToGame(String packageName);

    @Override
    protected void Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        // Сынақ ретінде Free Fire пакетін бақылауға аламыз
        String targetGame = "com.dts.freefireth";
        
        boolean isAttached = attachToGame(targetGame);
        
        if (isAttached) {
            Toast.makeText(this, "RAM бақылауға алынды! Билік іске қосылды.", Toast.LENGTH_LONG).show();
        } else {
            Toast.makeText(this, "Ойын табылмады. Қосылуын күтудеміз...", Toast.LENGTH_SHORT).show();
        }
    }
}
