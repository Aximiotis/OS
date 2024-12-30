#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;

    // First fork
    pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        printf("Child 1 Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    } else {
        // Parent process continues to fork again
        pid = fork();
        if (pid == -1) {
            perror("Fork failed");
            exit(1);
        } else if (pid == 0) {
            printf("Child 2 Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        } else {
            // Parent process continues to fork one more time
            pid = fork();
            if (pid == -1) {
                perror("Fork failed");
                exit(1);
            } else if (pid == 0) {
                printf("Child 3 Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
            } else {
                // Parent process
                printf("Parent Process: PID = %d\n", getpid());
            }
        }
    }

    return 0;
}
