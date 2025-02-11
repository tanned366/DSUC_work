#include <stdio.h>

int lin_rec_upper(int arr[], int n, int item) {
    if(arr[n-1] == item) return n-1;
    if(n == 0) return -1;
    else return lin_rec_upper(arr, n-1, item);
}

int lin_rec_lower(int arr[],int index, int n, int item) {
    if(index == n) return -1;
    if(arr[index] == item) return index;
    else return lin_rec_lower(arr, index+1, n, item);
}

int bin_rec(int arr[], int start, int end, int item) {
    int mid;
    if(start <= end) {
        mid = start + (end-start)/2;
        if(item == arr[mid]) return mid;
        else if(item < arr[mid]) return bin_rec(arr, start, mid-1, item);
        else return bin_rec(arr, mid+1, end, item);
    }
    return -1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int arr[], int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selectionsort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int minIndex = i;

        for(int j=0; j<n; j++){
            if(arr[j]<arr[minIndex])  minIndex = j;

            swap(&arr[minIndex], &arr[i]);
        }
    }
}

void merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    
    while (i <= mid) temp[k++] = arr[i++];
    
    while (j <= right) temp[k++] = arr[j++];

    for (i = left; i <= right; i++) arr[i] = temp[i];
}

void mergesort(int arr[], int temp[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergesort(arr, temp, left, mid);
        mergesort(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid, right);
    }
}

void quicksort(int arr[], int low, int high) {
    if(low < high) {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot-1);
        quicksort(arr, pivot+1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j=low; j<high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;     // return the index of the pivot element or partitioning index
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr)/sizeof(int);
    int item = 70;


    // printf("%d", lin_rec_lower(arr, 0, n, item));
    // printf("%d", bin_rec(arr, 0, n-1, item));
    
    return 0;
}