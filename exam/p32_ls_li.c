// Write a C program to implement ls  –li command which lists the files in a specified directory. Your program should Print 5 attributes of files.

// gcc -o ls_li p32_ls_li.c
// ./ls_li

#include <stdio.h>    // Standard I/O functions
#include <unistd.h>   // System calls like access()
#include <fcntl.h>    // File control options
#include <dirent.h>   // Directory handling functions
#include <time.h>     // Time functions for formatting timestamps
#include <sys/stat.h> // File status structure

int main(int argc, char *argv[]) {
    struct dirent *dir; // Structure to hold directory entry details
    struct stat fstat; // Structure to hold file attributes
    
    DIR *dp;
    // Open current directory
    dp = opendir(".");
    if (dp == NULL) {
        perror("Error opening directory");
        return 1;
    }

    // Print header for file details
    printf("--Inode--Mode--UID--GID--Access Time--Filename\n");

    // Read files in the directory
    while ((dir = readdir(dp)) != NULL) {
        // Get file attributes using stat()
        if (stat(dir->d_name, &fstat) == 0) {
            // Print file details
            printf("\n%ld %o %d %d %s %s\n", 
                   fstat.st_ino,     // Inode number
                   fstat.st_mode,    // File mode (permissions)
                   fstat.st_uid,     // User ID of owner
                   fstat.st_gid,     // Group ID of owner
                   ctime(&fstat.st_atime), // Last access time
                   dir->d_name        // Filename
            );
        }
        else {
            perror("Error retrieving file details");
        }
    }

    closedir(dp); // Close directory stream
    return 0;
}

// ./a.out /workspaces/USP/exam/xxx/


// #include <stdio.h>    
// #include <unistd.h>   
// #include <fcntl.h>    
// #include <dirent.h>   
// #include <time.h>     
// #include <sys/stat.h> 

// int main(int argc, char *argv[]) {
//     struct dirent *dir;
//     struct stat fstat;
//     DIR *dp;

//     // Check if directory argument is provided
//     if (argc < 2) {
//         printf("Usage: %s <directory_path>\n", argv[0]);
//         return 1;
//     }

//     // Open the specified directory
//     dp = opendir(argv[1]);
//     if (dp == NULL) {
//         perror("Error opening directory");
//         return 1;
//     }

//     printf("--Inode--Mode--UID--GID--Access Time--Filename\n");

//     while ((dir = readdir(dp)) != NULL) {
//         char filepath[1024];
//         snprintf(filepath, sizeof(filepath), "%s/%s", argv[1], dir->d_name);

//         if (stat(filepath, &fstat) == 0) {
//             printf("\n%ld %o %d %d %s %s\n", 
//                    fstat.st_ino,     
//                    fstat.st_mode,    
//                    fstat.st_uid,     
//                    fstat.st_gid,     
//                    ctime(&fstat.st_atime),
//                    dir->d_name        
//             );
//         } else {
//             perror("Error retrieving file details");
//         }
//     }

//     closedir(dp);
//     return 0;
// }