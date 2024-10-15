/**
 * File Name: sorting.cpp
 * Contributors: Amaya Joshi, Aissatou Barry, Omar Perez
 * Description: This file contains the implementation of various sorting algorithms 
 * such as insertion sort, merge sort, quicksort, randomized quicksort, and improved quicksort.
 */


#include "sorting.hpp"
#include <iostream
#include <algorithm> //For std::swap
using namespace std; 


/**
 * Insertion Sort Algorithm
 * 
 * Description: Sorts an array using the insertion sort algorithm.
 * 
 * @param arr - A pointer to the array that needs to be sorted.
 * @param n - The number of elements in the array.
 * 
 * @return void
 * 
 * The function directly modifies the input array.
 */
template <typename T>
void insertion_sort(T *arr, long n) {
    for (long i = 1; i < n; ++i) {
        T key = arr[i];
        long j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/**
 * Merge Sort (Recursive Helper Function)
 * 
 * Description: This is the recursive helper function for merge sort. It divides the array 
 * into two halves and recursively sorts and merges them.
 * 
 * @param arr - A pointer to the array to be sorted.
 * @param left - The starting index of the array.
 * @param right - The ending index of the array.
 * 
 * @return void
 */
template <typename T>
void merge_sort_recursive(T *arr, int left, int right) {
    if (left >= right) {
        return; // Base case
    }
    int mid = left + (right - left) / 2;
    // Sort first and second halves
    merge_sort_recursive(arr, left, mid);
    merge_sort_recursive(arr, mid + 1, right);
    // Merge the sorted halves
    int n1 = mid - left + 1;
    int n2 = right - mid;
    // Temporary arrays
    T *L = new T[n1];
    T *R = new T[n2];
    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];
    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    // Free dynamically allocated memory
    delete[] L;
    delete[] R;
}


/**
 * Merge Sort
 * 
 * Description: Sorts an array using the merge sort algorithm.
 * 
 * @param arr - A pointer to the array to be sorted.
 * @param length - The number of elements in the array.
 * 
 * @return void
 * 
 * This function acts as a driver for merge sort by calling the recursive helper function.
 */
template <typename T>
void merge_sort(T *arr, int length) 
{
    merge_sort_recursive(arr, 0, length - 1);
}


/**
 * Quicksort
 * 
 * Description: Sorts an array using the quicksort algorithm.
 * 
 * @param arr - A pointer to the array to be sorted.
 * @param n - The number of elements in the array.
 * 
 * @return void
 * 
 * This function sorts the input array in-place using the quicksort algorithm.
 */
template <typename T>
void quicksort(T *arr, long n){
    if(n<=1){
        return;
    }    

    long pivot_index=partiion(arr,n);
    quicksort(arr, pivot_index);

    quicksort(arr + pivot_index + 1, n - pivot_index - 1);

}

//partition first element
template <typename T>
long partition(T* arr, long n) {
    //First Element
    T pivot = arr[0];
    
    long i = 1; 
    long j = n - 1; 
    
    while (i <= j) {
        
        while (i <= j && arr[i] <= pivot) {
            i++;
        }
        
        while (i <= j && arr[j] > pivot) {
            j--;
        }
        
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[0], arr[j]);
    
    return j;
}

/**
 * Randomized Quicksort
 * 
 * Description: Sorts an array using randomized quicksort, which selects a random pivot.
 * 
 * @param arr - A pointer to the array to be sorted.
 * @param n - The number of elements in the array.
 * 
 * @return void
 * 
 * This function sorts the input array in-place using a randomly selected pivot for partitioning.
 */
template <typename T>
void randomized_quicksort (T *arr,long n){
    if (n<=1)
        return;
    long pivot_index= random_partition(arr,n);
    //left
    randomized_quicksort(arr, pivot_index);
    //right
    randomized_quicksort(arr+pivot_index +1, n- pivot_index-1);
    
}


/**
 * Random Partition for Randomized Quicksort
 * 
 * Description: Selects a random pivot element and partitions the array based on the pivot.
 * 
 * @param arr - A pointer to the array to be partitioned.
 * @param n - The number of elements in the array.
 * 
 * @return The index of the pivot after partitioning.
 */
template <typename T>
long random_partition(T* arr, long n){
    / Select a random index as the pivot
    long randomIndex = rand() % n;
    T pivot = arr[randomIndex];

    swap(arr[0], arr[randomIndex]);

    long i = 1;      
    long j = n - 1;  

    while (i <= j) {

        while (i <= j && arr[i] <= pivot) {
            i++;
        }

        while (i <= j && arr[j] > pivot) {
            j--;
        }

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[0], arr[j]);

    return j;
}


/**
 * Improved Quicksort
 * 
 * Description: Sorts an array using an improved version of quicksort that selects the median-of-three as the pivot.
 * 
 * @param arr - A pointer to the array to be sorted.
 * @param n - The number of elements in the array.
 * 
 * @return void
 * 
 * This function sorts the array in-place using the median-of-three quicksort.
 */
template <typename T>
void improved_quicksort(T *arr, long n) {
    // Base case: If the array has 1 or 0 elements, it is already sorted
    if (n <= 1) {
        return;
    }

    // Choose the median-of-three pivot: median of arr[0], arr[n/2], arr[n-1]
    long mid = n / 2;
    if (arr[0] > arr[mid]) std::swap(arr[0], arr[mid]);
    if (arr[0] > arr[n - 1]) std::swap(arr[0], arr[n - 1]);
    if (arr[mid] > arr[n - 1]) std::swap(arr[mid], arr[n - 1]);

    T pivot = arr[mid];

    // Partitioning step
    long i = 0;
    long j = n - 1;

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // Recursively apply improved_quicksort to the two sub-arrays
    improved_quicksort(arr, j + 1);           // Sort elements before the pivot
    improved_quicksort(arr + i, n - i);       // Sort elements after the pivot
}
