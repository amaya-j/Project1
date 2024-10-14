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
T* merge(T* left, long leftSize, T* right, long rightSize) {
    T* result = new T[leftSize + rightSize];
    long i = 0, j = 0, k = 0;
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) result[k++] = left[i++];
        else result[k++] = right[j++];
    }
    while (i < leftSize) result[k++] = left[i++];
    while (j < rightSize) result[k++] = right[j++];
    return result;
}

template <typename T>
T* merge_sort(T* arr, long n) {
    if (n <= 1) return arr;
    long mid = n / 2;
    T* left = merge_sort(arr, mid);
    T* right = merge_sort(arr + mid, n - mid);
    return merge(left, mid, right, n - mid);
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
