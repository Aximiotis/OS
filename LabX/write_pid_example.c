#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *file;
    pid_t pid;
    
    // Άνοιγμα του αρχείου για εγγραφή (θα δημιουργηθεί ή θα αντικατασταθεί αν υπάρχει)
    file = fopen("pids.txt", "w");
    if (file == NULL) {
        perror("Unable to open file");
        exit(1);
    }

    // Δημιουργία του παιδικού διαδικαστικού με fork
    pid = fork();

    if (pid == -1) {
        // Αν η fork αποτύχει
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Παιδική διαδικασία
        fprintf(file, "Child process PID: %d\n", getpid());
        printf("Child process PID: %d\n", getpid());
    } else {
        // Γονική διαδικασία
        fprintf(file, "Parent process PID: %d\n", getpid());
        printf("Parent process PID: %d\n", getpid());
    }

    // Κλείσιμο του αρχείου
    fclose(file);

    return 0;
}
