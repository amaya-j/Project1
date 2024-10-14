#include "sorting.hpp"
#include <iostream
#include <algorithm> //For std::swap
using namespace std; 

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


// Merge sort that takes only the array and the length of the array
template <typename T>
void merge_sort(T *arr, int length) 
{
    merge_sort_recursive(arr, 0, length - 1);
}



template <typename T>
void improved_quicksort(T *arr, long left, long right) {
    if (left < right) {
        // Choose the median of three as the pivot
        long mid = left + (right - left) / 2;
        if (arr[left] > arr[mid]) std::swap(arr[left], arr[mid]);
        if (arr[left] > arr[right]) std::swap(arr[left], arr[right]);
        if (arr[mid] > arr[right]) std::swap(arr[mid], arr[right]);

        T pivot = arr[mid];
        std::swap(arr[mid], arr[right - 1]); // Hide pivot near the end
        long i = left, j = right - 1;

        while (true) {
            while (arr[++i] < pivot); // Move i right past values < pivot
            while (arr[--j] > pivot); // Move j left past values > pivot
            if (i >= j) break; // Stop when indices cross
            std::swap(arr[i], arr[j]);
        }

        std::swap(arr[i], arr[right - 1]); // Restore pivot to its final position

        // Recursively sort the left and right sub-arrays
        improved_quicksort(arr, left, i - 1);
        improved_quicksort(arr, i + 1, right);
    }
}
