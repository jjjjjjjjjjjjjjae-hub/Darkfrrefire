#include <jni.h>
#include <string>
#include <cstring>

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_dark_injector_MainActivity_checkToken(JNIEnv *env, jobject thiz, jstring token) {
    const char *nativeToken = env->GetStringUTFChars(token, nullptr);
    bool result = (std::strcmp(nativeToken, "DARK-KEY-2026") == 0);
    env->ReleaseStringUTFChars(token, nativeToken);
    return result ? JNI_TRUE : JNI_FALSE;
}
