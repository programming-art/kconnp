#ifndef _CONNPD_H
#define _CONNPD_H

#include <linux/spinlock.h>

#define NR_MAX_OPEN_FDS 1024

#define CONNP_DAEMON_TSKP (connp_daemon)
#define CONNP_DAEMON_EXISTS() CONNP_DAEMON_TSKP
#define INVOKED_BY_CONNP_DAEMON() (current == CONNP_DAEMON_TSKP)

extern struct task_struct * volatile connp_daemon;

extern int connpd_init(void);
extern void connpd_destroy(void);

extern int connpd_unused_fds_push(int fd);
#define connpd_get_unused_fd()  connpd_unused_fds_pop()
extern int connpd_unused_fds_pop(void);

extern int connpd_close_pending_fds_push(int fd);
extern int connpd_close_pending_fds_pop(void);

#endif
