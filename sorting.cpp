#include "sorting.hpp"
#include <iostream>
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



