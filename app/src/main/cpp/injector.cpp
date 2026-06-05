#include <jni.h>
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <cstdlib>

// Функция: Пакет атауы арқылы Ойынның Процесс ID (PID) анықтау
int get_process_pid(const char* package_name) {
    DIR* dir = opendir("/proc");
    if (!dir) return -1;

    struct dirent* entry;
    while ((entry = readdir(dir))) {
        int pid = atoi(entry->d_name);
        if (pid > 0) {
            char cmdline_path[64];
            snprintf(cmdline_path, sizeof(cmdline_path), "/proc/%d/cmdline", pid);
            
            int fd = open(cmdline_path, O_RDONLY);
            if (fd >= 0) {
                char buf[256] = {0};
                read(fd, buf, sizeof(buf) - 1);
                close(fd);
                
                if (strcmp(buf, package_name) == 0) {
                    closedir(dir);
                    return pid; // Ойын табылды, оның PID-ін қайтару
                }
            }
        }
    }
    closedir(dir);
    return -1; // Ойын әлі қосылмаған
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_dark_freemod_MainActivity_attachToGame(JNIEnv* env, jobject thiz, jstring package_obj) {
    const char* package_name = env->GetStringUTFChars(package_obj, nullptr);
    
    int pid = get_process_pid(package_name);
    env->ReleaseStringUTFChars(package_obj, package_name);
    
    if (pid > 0) {
        // Бұл жерде біздің RAM-ды басып алу және "жер төледе қамау" логикасы іске қосылады
        return JNI_TRUE; 
    }
    
    return JNI_FALSE;
}
