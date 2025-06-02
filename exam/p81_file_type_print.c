// Write a C program that takes the file name as an argument and prints the type of the given file.


// gcc p81_file_type_print.c -o filetype
// ./filetype myfile.txt
// ./filetype file1.txt file2.txt /etc/passwd


// or 

// gcc p81_file_type_print
// ./a.out test.txt

#include <stdio.h>   // Required for printf
#include <stdlib.h>  // Required for exit
#include <sys/types.h>  // Required for data types
#include <sys/stat.h>  // Required for stat structure
#include <unistd.h> // Required for lstat function


int main(int argc, char *argv[]){
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> <file2> ...\n", argv[0]);
        exit(1);
    }
    struct stat fstat; // Structure to hold file information
    char *ptr; // String ptr to hold the type of file

    // Loop through each argument provided in the command line
    for (int i = 1; i < argc; i++){

        printf("%s: ", argv[i]);

        // Get file status
        lstat(argv[i], &fstat);
        
        // Check the file type using the mode field of the stat structure
        if (S_ISREG(fstat.st_mode))
            ptr = "regular";
        else if (S_ISDIR(fstat.st_mode))
            ptr = "directory";
        else if (S_ISCHR(fstat.st_mode))
            ptr = "character special";
        else if (S_ISBLK(fstat.st_mode))
            ptr = "block special";
        else if (S_ISFIFO(fstat.st_mode))
            ptr = "fifo";
        else if (S_ISLNK(fstat.st_mode))
            ptr = "symbolic link";
        else if (S_ISSOCK(fstat.st_mode))
            ptr = "socket";
        else
            ptr = "** unknown mode **";

        // Print the type of file
        printf("%s\n", ptr);
    }
    exit(0);
}