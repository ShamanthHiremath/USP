// Write a C program to demonstrate the usage of umask and chmod functions.

// gcc p91_unmask_chmod_func.c -o chmod_demo
// gcc umask.c -o umask

// # Run the programs
// ./p91_unmask_chmod_func
// ./umask

// # View the results
// ls -l foo bar

// p91_unmask_chmod_func.c

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
int main(){

    struct stat buf;
    // foo will be created with mode 0666
    stat("foo", &buf);

    // set umask to 022
    // umask sets the default file creation permissions.
    // default except, executable permission for group and others will be removed.
    chmod("foo", buf.st_mode & ~S_IXGRP);

    // foo will have mode 0644
    /* set absolute mode to "rw-r--r--" */
    chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    
    return 0;
}

// gcc umask.c -o umask_demo
// ./umask_demo

// // umask.c

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// #define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

// int main(){
//     umask(0);
//     creat("foo", RWRWRW);
//     umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
//     creat("bar", RWRWRW)
    
//     return 0;
// }