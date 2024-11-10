#include <stdio.h>
#include <string.h>
#include "mySort.h"

// Utility functions
void printArray(int arr[], int n);


// Test the sorting algorithms
int main() {
    int arr[] = {64, -134, -5, 0, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    unsigned int un = (unsigned int)n; //An unsigned version of n.
    //This is only used to avoid conversion warnings from the -Wconversion flag when using memcpy()
    
    int testArr[n];
    
    memcpy(testArr, arr, un * sizeof(int));
    printf("Original array: ");
    printArray(testArr, n);
    printf("\n");
    
    // Bubble Sort
    memcpy(testArr, arr, un * sizeof(int));
    bubbleSort(testArr, n);
    printf("Bubble sorted array: ");
    printArray(testArr, n);

    // CODE: do the same test cases for Insertion Sort, Merge Sort, Heap Sort, Counting Sort
    // You will submit main.c, and your project will be marked based on main.c as well

    //Insertion Sort
    memcpy(testArr, arr, un * sizeof(int));
    insertionSort(testArr, n);
    printf("Insertion sorted array: ");
    printArray(testArr, n);

    //Merge Sort
    memcpy(testArr, arr, un * sizeof(int));
    mergeSort(testArr, 0, n-1);
    printf("Merge sorted array: ");
    printArray(testArr, n);

    //Heap Sort
    memcpy(testArr, arr, un * sizeof(int));
    heapSort(testArr, n);
    printf("Heap sorted array: ");
    printArray(testArr, n);

    //Counting Sort
    memcpy(testArr, arr, un * sizeof(int));
    countingSort(testArr, n);
    printf("Counting sorted array: ");
    printArray(testArr, n);

    
    return 0;
}

// Helper functions
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

