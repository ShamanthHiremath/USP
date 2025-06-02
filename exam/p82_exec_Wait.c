// Write a C program to perform the following operations
//     i. To create a child process
//     ii. The child process should execute a program (using exec( )) to show the use of the access function
//     iii. The parent process should wait for the child process to exit
//     iv. Also print the necessary process IDs

// gcc p82_exec_Wait.c -o main
// run gcc p1.c -o p1 before running this code


// ./p82_exec_Wait

// main.c


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main() {
    pid_t pid;
    int status;
    pid_t parent_pid = getpid();

    // Create a child process
    pid = fork();

    if (pid == -1) {
        printf("Fork failed. Error code: %d\n", errno);
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        // Child process
        pid_t child_pid = getpid();
        printf("Child process (PID: %d) executing...\n", child_pid);

        // Execute the program using exec
        // run gcc p1.c -o p1 before running this code

        execl("./p1", "p1", "example.txt", (char *)NULL);
        printf("execl failed. Error code: %d\n", errno);
        exit(EXIT_FAILURE);
    } else {
        printf("Parent process (PID: %d) executing...\n", parent_pid);
        waitpid(pid, &status, 0);
        printf("Parent process: Child process (PID: %d) has exited.\n", pid);
    }

    return 0;
}
// run gcc p1.c -o p1 before running this code

// Note: The child process will execute the p1 program which checks for the existence of a file named "example.txt".

// p1.c

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// int main(int argc, char *argv[]) {
//     if (argc != 2) {
//         printf("Usage: %s <filename>\n", argv[0]);
//         exit(EXIT_FAILURE);
//     }

//     char *filename = argv[1];

//     if (access(filename, F_OK) == 0) {
//         printf("File '%s' exists and can be accessed.\n", filename);
//     } else {
//         printf("File '%s' does not exist or cannot be accessed.\n", filename);
//     }

//     return 0;
// }