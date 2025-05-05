// Write a C program that takes the file name as an argument and prints the type of the given file.

// gcc -o file_type p51_file_type.c
// ./file_type test.txt
// ./file_type test.txt my_folder device_file


#include <fcntl.h>      // File control definitions
#include <sys/types.h>  // Data types used in system calls
#include <sys/stat.h>   // Structure for file information
#include <stdlib.h>     // Standard library for exit()

int main(int argc, char *argv[]) {
    struct stat filestat; // Structure to store file information
    char *ptr;       // Pointer to hold file type description

    // Loop through each file argument provided by the user
    for (int i = 1; i < argc; i++) {
        printf("%s: ", argv[i]); // Print file name

        // Get file information using lstat()
        lstat(argv[i], &filestat);

        // Determine file type using mode flags
        if (S_ISREG(filestat.st_mode))
            ptr = "regular"; // Regular file
        else if (S_ISDIR(filestat.st_mode))
            ptr = "directory"; // Directory
        else if (S_ISCHR(filestat.st_mode))
            ptr = "character special"; // Character device
        else if (S_ISBLK(filestat.st_mode))
            ptr = "block special"; // Block device
        else if (S_ISFIFO(filestat.st_mode))
            ptr = "fifo"; // Named pipe
        else if (S_ISLNK(filestat.st_mode))
            ptr = "symbolic link"; // Symbolic link
        else if (S_ISSOCK(filestat.st_mode))
            ptr = "socket"; // Socket
        else
            ptr = "** unknown mode **"; // Unknown file type

        printf("%s\n", ptr); // Print the file type
    }

    exit(0); // Exit successfully
}