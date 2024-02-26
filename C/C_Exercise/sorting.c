#include <stdio.h>

// Function to swap two numbers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n, int ascending) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            // For ascending order
            if (ascending) {
                if (arr[j] > arr[j+1]) {
                    swap(&arr[j], &arr[j+1]);
                }
            }
            // For descending order
            else {
                if (arr[j] < arr[j+1]) {
                    swap(&arr[j], &arr[j+1]);
                }
            }
        }
    }
}

int main() {
    int arr[] = {-9, -1, 0, 56, 25, -32, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sorting in ascending order
    bubbleSort(arr, n, 1);
    printf("Sorted numbers in ascending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sorting in descending order
    bubbleSort(arr, n, 0);
    printf("Sorted numbers in descending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
