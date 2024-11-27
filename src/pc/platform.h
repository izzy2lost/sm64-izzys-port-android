#ifndef _SM64_PLATFORM_H_
#define _SM64_PLATFORM_H_

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* Platform-specific functions and whatnot */

#define SYS_MAX_PATH 1024 // FIXME: define this on different platforms

// NULL terminated list of platform-specific read-only data paths
extern const char *sys_ropaths[];

// Cross-platform implementations of misc functions
char *sys_strdup(const char *src);
char *sys_strlwr(char *src);
int sys_strcasecmp(const char *s1, const char *s2);

// Path functions (declarations)
const char *sys_user_path(void);
const char *sys_exe_path(void);

// Fatal error function declaration
void sys_fatal(const char *fmt, ...) __attribute__ ((noreturn));

#endif // _SM64_PLATFORM_H_
