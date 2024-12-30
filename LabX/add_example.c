#include <stdio.h>

// Συνάρτηση add() που παίρνει 3 ακέραιους αριθμούς και επιστρέφει το άθροισμά τους μέσω αναφοράς
void add(int *a, int *b, int *c) {
    *a = *a + *b + *c;  // Υπολογισμός του αθροίσματος και αποθήκευση στο πρώτο όρισμα
}

int main() {
    int x, y, z;

    // Ζήτα από τον χρήστη να εισάγει 3 αριθμούς
    printf("Enter three integers: ");
    scanf("%d %d %d", &x, &y, &z);

    // Κλήση της συνάρτησης add με αναφορά
    add(&x, &y, &z);

    // Εκτύπωση του αποτελέσματος
    printf("The sum of the three integers is: %d\n", x);

    return 0;
}
