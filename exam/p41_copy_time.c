// Write a program to copy access and modification time of a file to another file using utime function.

// gcc -o copy_time p41_copy_time.c
// ./copy_time file1.txt file2.txt

#include <stdio.h>    // Standard I/O functions
#include <sys/stat.h> // File status structure
#include <sys/types.h>// Data types like mode_t
#include <unistd.h>   // System calls like stat(), utime()
#include <utime.h>    // Functions to update file access/modification times
#include <time.h>     // Functions to format time output

int main(int argc, char *argv[]) {
    struct stat fstat1; // Structure to store file details (source file)
    struct stat fstat2; // Structure to store file details (destination file)
    struct utimbuf times;  // Structure to update file times

    // Get file attributes of source and destination files
    stat(argv[1], &fstat1);  // Retrieves metadata (timestamps) of source file
    stat(argv[2], &fstat2);  // Retrieves metadata (timestamps) of destination file

    // Display original timestamps of source file
    printf("Before Copying ...\n");
    printf("Access Time %s\nModification Time %s\n", ctime(&fstat1.st_atime), ctime(&fstat1.st_mtime));

    // Copy timestamps from destination file to source file
    times.modtime = fstat2.st_mtime;  // Set modification time from destination file
    times.actime = fstat2.st_atime;   // Set access time from destination file
    utime(argv[1], &times);              // Apply updated timestamps to source file

    // Get updated attributes of source file after copying timestamps
    stat(argv[1], &fstat1);

    // Display modified timestamps of source file
    printf("After Copying ...\n");
    printf("Access Time %s\nModification Time %s\n", ctime(&fstat1.st_atime), ctime(&fstat1.st_mtime));

    return 0;
}