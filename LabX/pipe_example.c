#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>  // Include this header for wait()

int main() {
    int pipefd[2];  // Array to hold the two ends of the pipe (pipefd[0] for read, pipefd[1] for write)
    pid_t pid;
    char message[] = "Hello from Parent!";
    char buffer[100];

    // Create the pipe
    if (pipe(pipefd) == -1) {
        perror("pipe failed");
        exit(1);
    }

    // Create a new process using fork()
    pid = fork();

    if (pid == -1) {
        // Fork failed
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child process: close write end of pipe and read the message from the pipe
        close(pipefd[1]);  // Close unused write end of the pipe

        // Read from the pipe
        read(pipefd[0], buffer, sizeof(buffer));

        // Print the received message
        printf("Child received: %s\n", buffer);

        // Close the read end of the pipe
        close(pipefd[0]);
    } else {
        // Parent process: close read end of pipe and write the message to the pipe
        close(pipefd[0]);  // Close unused read end of the pipe

        // Write the message to the pipe
        write(pipefd[1], message, strlen(message) + 1);

        // Close the write end of the pipe after sending the message
        close(pipefd[1]);

        // Wait for the child process to finish
        wait(NULL);  // This is where we wait for the child to complete
    }

    return 0;
}

