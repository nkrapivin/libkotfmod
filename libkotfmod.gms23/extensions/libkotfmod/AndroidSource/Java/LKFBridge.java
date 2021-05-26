package ${YYAndroidPackageName};

import com.nkrapivindev.libkotfmod.LKFNative;
import com.yoyogames.runner.RunnerJNILib;
import android.content.Intent;
import android.content.res.Configuration;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuItem;
import android.app.Dialog;
import android.view.MotionEvent;
import android.util.Log;

public class LKFBridge extends LKFNative implements IExtensionBase {
    // inherit the constructor of LKFNative so the libraries will get loaded. (Java doesn't inherit parameterless constructors by default)
    public LKFBridge() {super();}

    public boolean initFlag = false; // already initialized flag.
    public void Init() {
    	if (!initFlag) {
	    	Log.i("yoyo", "LKFBridge - Initializing Java FMOD...");
	    	org.fmod.FMOD.init(RunnerJNILib.GetApplicationContext());
	    	initFlag = true;
    	}
    	else {
    		Log.i("yoyo", "LKFBridge - FMOD is already initialized.");
    	}
    }

    // don't forget to unregister FMOD when we don't need it anymore
    // (that's why I also implement IExtensionBase!)
    public void onDestroy() {
    	if (initFlag) {
	    	Log.i("yoyo", "LKFBridge - Closing Java FMOD...");
	    	org.fmod.FMOD.close();
    	}
    	else {
    		Log.i("yoyo", "LKFBridge - Tried to destroy without initializing FMOD...");
    	}
    }

    // empty methods, ignore. we have to finish implementing IExtensionBase after all...
    public void onStart(){}
	public void onRestart(){}
	public void onStop(){}
	public void onPause(){}
	public void onResume(){}
	public void onConfigurationChanged(Configuration a){}
	public void onRequestPermissionsResult(int a,String b[],int[] c){}
	public void onActivityResult(int a,int b,Intent c){}
	public boolean onKeyLongPress(int a,KeyEvent b){return false;}
	public void onWindowFocusChanged(boolean a){}
	public boolean onCreateOptionsMenu(Menu a){return false;}
	public boolean onOptionsItemSelected(MenuItem a){return false;}
	public boolean onKeyDown(int a,KeyEvent b){return false;}
	public boolean onKeyUp(int a,KeyEvent b){return false;}
	public Dialog onCreateDialog(int a){return null;}
	public boolean performClick(){return false;}
	public boolean onTouchEvent(final MotionEvent a){return false;}
	public boolean onGenericMotionEvent(MotionEvent a){return false;}
	public boolean dispatchGenericMotionEvent(MotionEvent a){return false;}
	public boolean dispatchKeyEvent(KeyEvent a){return false;}
	public void onNewIntent(Intent a){}
} // public class LKFBridge extends LKFNative implements IExtensionBase {
