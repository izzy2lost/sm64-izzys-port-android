#ifndef _SM64_PLATFORM_H_
#define _SM64_PLATFORM_H_

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* Platform-specific functions and whatnot */

#define SYS_MAX_PATH 1024 // FIXME: define this on different platforms

// NULL terminated list of platform specific read-only data paths
extern const char *sys_ropaths[];

// crossplatform impls of misc stuff
char *sys_strdup(const char *src);
char *sys_strlwr(char *src);
int sys_strcasecmp(const char *s1, const char *s2);

// path stuff
#ifdef TARGET_ANDROID
#include "platform.h"

// Android-specific implementation to get the game directory
const char* get_gamedir(void) {
    SDL_bool privileged_write = SDL_FALSE, privileged_manage = SDL_FALSE;
    static char gamedir_unprivileged[SYS_MAX_PATH] = { 0 }, gamedir_privileged[SYS_MAX_PATH] = { 0 };
    const char *basedir_unprivileged = SDL_AndroidGetExternalStoragePath();
    const char *basedir_privileged = SDL_AndroidGetTopExternalStoragePath();

    snprintf(gamedir_unprivileged, sizeof(gamedir_unprivileged), 
             "%s", basedir_unprivileged);
    snprintf(gamedir_privileged, sizeof(gamedir_privileged), 
             "%s/%s", basedir_privileged, ANDROID_APPNAME);

    // Android 10 and below
    privileged_write = SDL_AndroidRequestPermission("android.permission.WRITE_EXTERNAL_STORAGE");
    // Android 11 and up
    privileged_manage = SDL_AndroidRequestPermission("android.permission.MANAGE_EXTERNAL_STORAGE");
    return (privileged_write || privileged_manage) ? gamedir_privileged : gamedir_unprivileged;
}

const char *sys_user_path(void) {
    static char path[SYS_MAX_PATH] = { 0 };

    const char *basedir = get_gamedir();
    snprintf(path, sizeof(path), "%s/user", basedir);

    if (!fs_sys_dir_exists(path) && !fs_sys_mkdir(path))
        path[0] = 0; // somehow failed, we got no user path
    return path;
}

const char *sys_exe_path(void) {
    static char path[SYS_MAX_PATH] = { 0 };
    
    const char *basedir = get_gamedir();
    snprintf(path, sizeof(path), "%s", basedir);

    if (!fs_sys_dir_exists(path) && !fs_sys_mkdir(path))
        path[0] = 0; // somehow failed, we got no exe path
    return path;
}

#else // Non-Android fallback (for other platforms)
const char *sys_user_path(void) {
    static char path[SYS_MAX_PATH] = { 0 };
    snprintf(path, sizeof(path), "%s/user", "./"); // Default user path

    if (!fs_sys_dir_exists(path) && !fs_sys_mkdir(path))
        path[0] = 0; // Failed to create or find user path
    return path;
}

const char *sys_exe_path(void) {
    static char path[SYS_MAX_PATH] = { 0 };
    snprintf(path, sizeof(path), "%s", "./"); // Default exe path

    if (!fs_sys_dir_exists(path) && !fs_sys_mkdir(path))
        path[0] = 0; // Failed to create or find exe path
    return path;
}

#endif // TARGET_ANDROID

// shows an error message in some way and terminates the game
void sys_fatal(const char *fmt, ...) __attribute__ ((noreturn));

#endif // _SM64_PLATFORM_H_
