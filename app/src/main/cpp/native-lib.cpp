#include <jni.h>
#include <string>
#include <android/log.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_zhy_NDKDemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject obc) {
    std::string hello = "Hello from C++";
    __android_log_print(ANDROID_LOG_ERROR,"TAG","hello");
    jclass jclass1 = env->FindClass("com/zhy/NDKDemo/MainActivity");
    jmethodID mid = env->GetMethodID(jclass1,"showToast","()V");
    env->CallVoidMethod(obc,mid);
    return env->NewStringUTF(hello.c_str());
}
