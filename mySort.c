#include <stdio.h>
#include <stdlib.h>
#include "mySort.h"


void swap(int *x, int *y) { //Pass in pointers x & y that point to the two integers we want to swap
    int temp = *x; //define a temp variable that's equal to the value x points at
    *x = *y; //set the int that x points to equal to the int that y points to
    *y = temp; //set the int that y points to equal to the temp variable (the former value of int x)
}

// Bubble Sort; TC = O(n^2)
void bubbleSort(int arr[], int n) { //n is the length of the array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

//Insertion Sort; TC = O(n^2)
void insertionSort(int arr[], int n){
    for (int i=1; i < n-1; i++) { //iterate through all elements of the list, starting at arr[1] (skip arr[0])
        int j = i;
        /*While j is above index arr[0] & the index to its left (arr[j-1]) has a higher value than arr[j],
        swap the values for arr[j] and arr[j-1], then make j = arr[j-1].
        As i iterate through the list, j will be moved to the left until it's value is sorted.*/
        while (j > 0 && arr[j] < arr[j-1]){
            swap(&arr[j], &arr[j-1]);
            j--;
        }
    }
}

//Merge Sort; TC = O(nlog(n))
void merge(int arr[], int start, int mid, int end);

void mergeSort(int arr[], int l, int r){

    /*Recursively splits array into multiple single index arrays
    l is for the left index of the array, and r is for the right index
    So for example, when using this function on an array you want to sort, 
    l should be 0 and r should be the size of the array - 1*/

    if (l < r){ //This acts as a recursion exit condition
        int m = (l + r-1)/2; //Subtract 1 from r due to index 0

        //Recursive statements to sort left & right halves of arr[]
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    } 
}

void merge(int arr[], int start, int mid, int end){
    /*Four parameters: the array we want to merge into (arr),
    and three integer values representing the first, middle,
    and last values of an array.
    Two arrays (left[start..mid] & right[mid+1..end] will be merged to create the sorted array (arr))*/

    int nl = mid - start + 1; //length of left array (add 1 due to index 0)
    int nr = end - mid;

    int left[nl], right[nr]; //Declaring the (temporary) arrays left[start..mid] & right[mid+1, end]

    //Add data to temporary arrays
    for (int i = 0; i < nl; i++){left[i] = arr[start+i];}
    for (int j=0; j < nr; j++){right[j] = arr[mid+1+j];}

    int i=0; //i is the index value for left[]
    int j=0; //j is the index value for right[]
    int k=start; //k is the index value for arr[]

    /*while i & j are valid indexes for their respective arrays, 
    whichever index has a smaller value will be placed at arr[k].
    Keep doing this until all values from both lists have been merged into arr*/
    while (i < nl && j < nr){
        if(left[i] < right[j]){
            arr[k] = left[i];
            i++;
        }else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    
    while (i < nl){
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < nr){
        arr[k] = right[j];
        j++;
        k++;
    }
}

//Heap Sort; TC = O(nlogn)
void heapify(int arr[], int n, int i);

void heapSort(int arr[], int n){

    for (int i=n/2-1; i >=0; i--){ //Create a max heap
        heapify(arr, n, i);
        }

    for (int i=n-1; i >=0; i--){ //Iterate through the array until array is sorted
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void heapify(int arr[], int n, int i){
    //Turns a heap into a max heap (essentially sorts a heap)
    /*Three parameters: the array we are using for the max heap (arr[]),
    the size of the array/heap (n),
    and the index i, which represents whatever node of the heap we are currently looking at.*/

    int left = 2*i+1; //The left chind node of i
    int right = 2*i + 2; //The right child node of i

    int largest = i; //The node with the largest value, initially set to i

    /*If the left node's index value is within the size of the array,
    and the left node's value is larger than the largest node (i),
    the left node is the new largest node*/
    if (left < n && arr[left] > arr[largest]){
        largest = left;
    }
    /*If the right node's index value is within the size of the array,
    and the right node's value is larger than the largest node (left or i),
    the right node is the new largest node*/
    if (right < n && arr[right] > arr[largest]){
        largest = right;
    }
    /*If the largest node is no longer i (it was changed to either of i's child nodes),
    then swap the positions of i and the largest node, which should move i down the heap*/
    if (largest != i){
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
    /*Since heapify is called recursively, it will essentially "float node i down the heap"
    until it's sorted in its correct position*/
}

//Counting Sort TC = O(n+m)
void countingSort(int arr[], int n){

    unsigned int un = (unsigned int)n;
    //Declare variables for the min & max values in the array
    //We can initially set them as any valid value in the array
    int minValueInit, maxValue;
    minValueInit = arr[0], maxValue = arr[1];

    //Find the minumum value in the array
    for (int i=0; i < n; i++){
        if (minValueInit > arr[i]){minValueInit = arr[i];}
    }

    /*Subtract the minimum value from each value in the array so that all values are ensured to be positive
    We must do this since any indexes with negative values would not work with the countArr[] array,
    as each value from arr[] should have a corresponding index in countArr[],
    and an array cannot have negative indexes. Once we have the sorted list, we can simply
    add the minimum value back to each value in the array*/
    for (int i=0; i < n; i++){arr[i] -= minValueInit;}
    int minValue = 0; //minValue - minValue = 0, so 0 must be the new minumum value

    //Find the new max value
    for (int i=0; i < n; i++){
        if (maxValue < arr[i]){maxValue = arr[i];}
    }
    
    //Find the range of numbers, as each number from minValue to maxValue will have it's own index in countArr
    int range = maxValue - minValue + 1;
    unsigned int urange = (unsigned int)range; //An unsigned varsion of range
    //This is used in some lines instead of range to avoid conversion warnings from the -Wconversion flag

    //Initializing countArr[] as an array of zeroes using calloc()
    int* countArr = calloc(urange, sizeof(int));

    if (countArr == NULL){
        printf("CountingSort: Memory allocation failed. Exiting the program.\n");
        return;
    }

    //For every occurrence of a value, add one to that value's corresponding countArr index's value
    for (int i=0; i < n; i++){countArr[arr[i]]++;}

    /*Starting from the 2nd index (countArr[1]), cumulatively add the value from the previous index
    to the current index in the loop. This will allow us to place these values into their sorted positions*/
    for (int i=1; i < range; i++){countArr[i] += countArr[i-1];}

    /*Iterating through arr[] in reverse, use arr[i]'s value to access the value at countArr[arr[i]].
    Whatever the value is at countArr[arr[i]] - 1 will give the sorted index for the value at arr[i]
    These values are placed into a temporary (sortedArr[]) list with the same length as arr[],
    so that we don't displace already sorted values as we iterate through arr[]*/
    int* sortedArr = (int*)malloc(n*sizeof(int));

    if (sortedArr == NULL){
        printf("CountingSort: Memory allocation failed. Exiting the program.\n");
        return;
    }

    for(int i=n-1; i >= 0; i--){
        int j = arr[i];
        sortedArr[countArr[j]-1] = j;
        countArr[j]--;
    }

    //We finally copy all the values from sortedArr[] into arr[]
    //We also shouldn't forget to add the initial minValue back to each value in the array
    for (int i=0; i < n; i++) {arr[i] = sortedArr[i];}
    for (int i=0; i < n; i++){arr[i] += minValueInit;}

    free(countArr);
    free(sortedArr);


}
