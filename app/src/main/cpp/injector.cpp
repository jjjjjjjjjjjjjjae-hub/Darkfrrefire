#include <jni.h>
#include <string>
#include <cstring>
#include <android/log.h>

#define LOG_TAG "DarkInjector"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_dark_freemod_MainActivity_checkToken(JNIEnv *env, jobject thiz, jstring token) {
    const char *nativeToken = env->GetStringUTFChars(token, nullptr);
    if (std::strcmp(nativeToken, "DARK-KEY-2026") == 0) {
        env->ReleaseStringUTFChars(token, nativeToken);
        return JNI_TRUE;
    }
    env->ReleaseStringUTFChars(token, nativeToken);
    return JNI_FALSE;
}
