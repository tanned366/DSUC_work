#include <stdio.h>

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Move n-1 disks from source to auxiliary, using destination as helper
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Move nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Move n-1 disks from auxiliary to destination, using source as helper
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;

    // Get number of disks from user
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Call the function to solve Tower of Hanoi
    printf("Tower of Hanoi solution for %d disks:\n", n);
    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}
