// umask.c
// gcc umask.c -o umask_demo
// ./umask_demo

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(){
    // Set the umask to 0, allowing all permissions for new files and directories created by this process.
    umask(0);
    
    // Create a file with read and write permissions for user, group, and others.
    creat("foo", RWRWRW);
    
    // Set the umask to allow only read and write permissions for group and others.
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    
    // Create another file with the new umask settings.
    creat("bar", RWRWRW);
    
    return 0;
}