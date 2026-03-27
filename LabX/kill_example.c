#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>  // Προσθήκη για τη συνάρτηση wait

// Signal handler function
void handle_signal(int sig) {
    if (sig == SIGUSR1) {
        printf("Child process received SIGUSR1 signal from parent.\n");
    }
}

int main() {
    pid_t pid;

    // Create a child process using fork
    pid = fork();

    if (pid == -1) {
        // Fork failed
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        // Set up the signal handler for SIGUSR1
        signal(SIGUSR1, handle_signal);

        // The child process will now wait for the signal
        printf("Child process waiting for signal from parent...\n");
        while (1) {
            // Child is just waiting for the signal (infinite loop)
            pause();  // Pause and wait for signal
        }
    } else {
        // Parent process
        // Parent process will wait for a few seconds before sending the signal
        sleep(2);

        // Send SIGUSR1 to the child process
        kill(pid, SIGUSR1);
        printf("Parent process sent SIGUSR1 signal to child.\n");

        // Wait for the child to handle the signal
        wait(NULL);  // Περιμένει να τελειώσει το παιδί
    }

    return 0;
}

