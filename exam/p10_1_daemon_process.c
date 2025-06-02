// Write a C program such that it initializes itself as a Daemon Process.

// gcc p10_1_daemon_process.c -o daemon
// ./daemon

// To stop the daemon process, you can use the following commands:
// ps aux | grep daemon
// tail -f /var/log/syslog
// sudo kill <PID>


// Write a C program such that it initializes itself as a Daemon Process.
#include<stdio.h> 
#include<stdlib.h> 
#include<sys/stat.h> 
#include<sys/types.h> 
#include<syslog.h> 
#include<unistd.h> 
#include<fcntl.h> 
void create_daemon(){ 
    pid_t pid=fork(); 

    if(pid<0){ 
        exit(EXIT_FAILURE); 
    } 

    if(pid>0){ 
        exit(EXIT_SUCCESS); 
    } 

    if(setsid()<0){ 
        exit(EXIT_FAILURE); 
    } 

    umask(0); 

    if(chdir("/")<0){ 
        exit(EXIT_FAILURE); 
    } 

    open("/dev/null",O_RDONLY); 
    open("/dev/null",O_WRONLY); 
    open("/dev/null",O_RDWR); 

    close(STDIN_FILENO); 
    close(STDOUT_FILENO); 
    close(STDERR_FILENO); 
} 

int main(){ 
    create_daemon(); 
    openlog("daemon_ex",LOG_PID,LOG_DAEMON); 
    while(1){ 
        syslog(LOG_NOTICE,"Daemon is running...\n"); 
        sleep(30); 
    } 
    closelog(); 
    return EXIT_SUCCESS; 
}