
#ifndef __IRT_ZCALLS_H__
#define __IRT_ZCALLS_H__

#include <sys/statvfs.h>
#include "zrt.h"

#define PASSWD_NAME  "LOGNAME"
#define PASSWD_UID   "UID"
#define PASSWD_GID   "GID"
#define PASSWD_HOME  "HOME"
#define PASSWD_SHELL "SHELL"

#define USER_ID_STUB  1
#define GROUP_ID_STUB 1

extern int (*__zcall_fcntl) (int fd, int cmd, ...);
       int (*__zcall_fcntl) (int fd, int cmd, ...);
extern int (*__zcall_rename)(const char *old, const char *new);
       int (*__zcall_rename)(const char *old, const char *new);
extern ssize_t (*__zcall_readlink)(const char *path, char *buf, size_t bufsize);
       ssize_t (*__zcall_readlink)(const char *path, char *buf, size_t bufsize);
extern int (*__zcall_symlink)(const char *oldpath, const char *newpath);
       int (*__zcall_symlink)(const char *oldpath, const char *newpath);
extern int (*__zcall_statvfs)(const char* path, struct statvfs *buf);
       int (*__zcall_statvfs)(const char* path, struct statvfs *buf);
extern int (*__zcall_link)(const char *oldpath, const char *newpath);
       int (*__zcall_link)(const char *oldpath, const char *newpath);
extern int (*__zcall_unlink)(const char *pathname);
       int (*__zcall_unlink)(const char *pathname);
extern int (*__zcall_rmdir)(const char *pathname);
       int (*__zcall_rmdir)(const char *pathname);
extern int (*__zcall_mkdir)(const char *pathname, mode_t mode);
       int (*__zcall_mkdir)(const char *pathname, mode_t mode);
extern int (*__zcall_chmod)(const char *path, mode_t mode);
       int (*__zcall_chmod)(const char *path, mode_t mode);
extern int (*__zcall_fchmod)(int fd, mode_t mode);
       int (*__zcall_fchmod)(int fd, mode_t mode);
extern int (*__zcall_chown)(const char *path, uid_t owner, gid_t group);
       int (*__zcall_chown)(const char *path, uid_t owner, gid_t group);
extern int (*__zcall_fchown)(int fd, uid_t owner, gid_t group);
       int (*__zcall_fchown)(int fd, uid_t owner, gid_t group);
extern int (*__zcall_ftruncate)(int fd, off_t length);
       int (*__zcall_ftruncate)(int fd, off_t length);
extern int (*__zcall_stat_realpath) (const char *abspathname, struct stat *);
       int (*__zcall_stat_realpath) (const char *abspathname, struct stat *);
extern int (*__zcall_get_phys_pages)(void);
       int (*__zcall_get_phys_pages)(void);
extern int (*__zcall_get_avphys_pages)(void);
       int (*__zcall_get_avphys_pages)(void);
extern int (*__zcall_fchdir)(int fd);
       int (*__zcall_fchdir)(int fd);
extern int (*__zcall_utime)(const char *filename, const struct utimbuf *times);
       int (*__zcall_utime)(const char *filename, const struct utimbuf *times);
extern int (*__zcall_utimes)(const char *filename, const struct timeval times[2]);
       int (*__zcall_utimes)(const char *filename, const struct timeval times[2]);
extern int (*__zcall_utimensat)(int dirfd, const char *pathname,
                                const struct timespec times[2], int flags);
       int (*__zcall_utimensat)(int dirfd, const char *pathname,
                                const struct timespec times[2], int flags);


#define INIT_ZCALLS {							\
	/*IRT syscalls can be redefined, it's totally saves nacl implementation*/ \
	struct zcalls_init_t* zcalls;					\
	if ( ZCALLS_INIT == __query_zcalls(ZCALLS_INIT, (void**)&zcalls) && \
	     zcalls ){							\
	    /*basic calls*/						\
	    __nacl_irt_exit        = zcalls->exit;			\
	    __nacl_irt_gettod      = zcalls->gettod;			\
	    __nacl_irt_clock       = zcalls->clock;			\
	    __nacl_irt_nanosleep   = zcalls->nanosleep;			\
	    __nacl_irt_sched_yield = zcalls->sched_yield;		\
	    __nacl_irt_sysconf     = zcalls->sysconf;			\
	    /*fdio calls*/						\
	    __nacl_irt_close       = zcalls->close;			\
	    __nacl_irt_dup         = zcalls->dup;			\
	    __nacl_irt_dup2        = zcalls->dup2;			\
	    __nacl_irt_read        = zcalls->read;			\
	    __nacl_irt_write       = zcalls->write;			\
	    __nacl_irt_seek        = zcalls->seek;			\
	    __nacl_irt_fstat       = zcalls->fstat;			\
	    __nacl_irt_getdents    = zcalls->getdents;			\
	    /*filename calls*/						\
	    __nacl_irt_open        = zcalls->open;			\
	    __nacl_irt_stat        = zcalls->stat;			\
	    /*memory calls*/						\
	    __nacl_irt_sysbrk      = zcalls->sysbrk;			\
	    __nacl_irt_mmap        = zcalls->mmap;			\
	    __nacl_irt_munmap      = zcalls->munmap;			\
	    /*dyncode calls*/						\
	    __nacl_irt_dyncode_create = zcalls->dyncode_create;		\
	    __nacl_irt_dyncode_modify = zcalls->dyncode_modify;		\
	    __nacl_irt_dyncode_delete = zcalls->dyncode_delete;		\
	    /*thread calls*/						\
	    __nacl_irt_thread_create = zcalls->thread_create;		\
	    __nacl_irt_thread_exit = zcalls->thread_exit;		\
	    __nacl_irt_thread_nice = zcalls->thread_nice;		\
	    /*mutes calls*/						\
	    __nacl_irt_mutex_create = zcalls->mutex_create;		\
	    __nacl_irt_mutex_destroy = zcalls->mutex_destroy;		\
	    __nacl_irt_mutex_lock  = zcalls->mutex_lock;		\
	    __nacl_irt_mutex_unlock = zcalls->mutex_unlock;		\
	    __nacl_irt_mutex_trylock = zcalls->mutex_trylock;		\
	    /*cond calls*/						\
	    __nacl_irt_cond_create  = zcalls->cond_create;		\
	    __nacl_irt_cond_destroy = zcalls->cond_destroy;		\
	    __nacl_irt_cond_signal  = zcalls->cond_signal;		\
	    __nacl_irt_cond_broadcast = zcalls->cond_broadcast;		\
	    __nacl_irt_cond_wait      = zcalls->cond_wait;		\
	    __nacl_irt_cond_timed_wait_abs = zcalls->cond_timed_wait_abs; \
	    /*tls calls*/						\
	    __nacl_irt_tls_init       = zcalls->tls_init;		\
	    __nacl_irt_tls_get        = zcalls->tls_get;		\
	    /*open_resource calls*/					\
	    __nacl_irt_open_resource  = zcalls->open_resource;		\
	    /*clock calls*/						\
	    __nacl_irt_clock_getres   = zcalls->getres;			\
	    __nacl_irt_clock_gettime  = zcalls->gettime;		\
	    /*another calls*/						\
	    __nacl_irt_chdir          = zcalls->chdir;			\
	    __nacl_irt_select         = zcalls->select;			\
	    								\
	    /*run zcall init*/						\
	    zcalls->preinit();						\
	}								\
    }


#define INIT_ZCALLS_NONSYSCALLS {					\
        /*IRT syscalls can be redefined, it's totally saves nacl implementation*/ \
	struct zcalls_nonsyscalls_t* zcalls;				\
	if ( ZCALLS_NONSYSCALLS == __query_zcalls(ZCALLS_NONSYSCALLS, (void**)&zcalls) && \
	     zcalls ){							\
	    __zcall_fcntl          = zcalls->fcntl;			\
	    __zcall_rename         = zcalls->rename;			\
	    __zcall_readlink       = zcalls->readlink;			\
	    __zcall_symlink        = zcalls->symlink;			\
	    __zcall_statvfs        = zcalls->statvfs;			\
	    __zcall_link           = zcalls->link;			\
	    __zcall_unlink         = zcalls->unlink;			\
	    __zcall_rmdir          = zcalls->rmdir;			\
	    __zcall_mkdir          = zcalls->mkdir;			\
	    __zcall_chmod          = zcalls->chmod;			\
	    __zcall_fchmod         = zcalls->fchmod;			\
	    __zcall_chown          = zcalls->chown;			\
	    __zcall_fchown         = zcalls->fchown;			\
	    __zcall_ftruncate      = zcalls->ftruncate;			\
	    __zcall_stat_realpath  = zcalls->stat_realpath;		\
	    __zcall_get_phys_pages = zcalls->get_phys_pages;		\
	    __zcall_get_avphys_pages = zcalls->get_avphys_pages;	\
	    __zcall_fchdir         = zcalls->fchdir;			\
            __zcall_utime          = zcalls->utime;                     \
            __zcall_utimes         = zcalls->utimes;                    \
            __zcall_utimensat      = zcalls->utimensat;                 \
	}								\
    }

#endif //__IRT_ZCALLS_H__
