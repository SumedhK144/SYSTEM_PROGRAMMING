//EVERY process has unique ID's
//PID -> process id
//PPID -> parent process id
//UID->real user id
//GID->real group id
//EUID->effective user id
//EGID->effective group id
#include <stdio.h>
#include <unistd.h>

int main(void){
    pid_t pid,p_pid;
    uid_t r_uid,e_uid;
    gid_t r_gid,e_gid;

    pid = getpid();
    p_pid = getppid();
    printf("PID = %-19ld PARENT PID: %-10ld\n",pid,p_pid);

    r_uid = getuid();
    e_uid = geteuid();
    printf("REAL USER ID: %-10d EFFECTIVE USER ID: %-15d\n",r_uid,e_uid);

    r_gid = getgid();
    e_gid = getegid();
    printf("REAL GROUP ID: %-10d EFFECTIVE GROUP ID: %-15d\n",r_gid,e_gid);

    return 0;
}