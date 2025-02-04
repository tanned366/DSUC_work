#include <stdio.h>

void trav(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insert(int arr[], int *n) {
    int ele, pos;
    printf("Enter the element: \n");
    scanf("%d", &ele);
    printf("Enter the position: \n");
    scanf("%d", &pos);

    int i = *n;
    while (i > pos) {  // Shift elements to the right
        arr[i] = arr[i - 1];
        i--;
    }
    arr[pos] = ele;
    (*n)++;
}

void del(int arr[], int *n) {
    int pos;
    printf("Enter the position to delete: \n");
    scanf("%d", &pos);

    int i = pos;
    while (i < *n - 1) {  // Shift elements left
        arr[i] = arr[i + 1];
        i++;
    }
    (*n)--;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr)/sizeof(int);

    trav(arr, n);    
    insert(arr, &n);
    trav(arr, n);
    del(arr, &n);
    trav(arr, n);
    
    return 0;
}
