#include "sorting.hpp"
#include <iostream>
#include "sorting.cpp"
#include <cassert>
using namespace std;


template <typename T>
void print_array(T *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Test empty array
void test_empty_array() {
    int arr[] = {};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Testing Empty Array:\n";
    cout << "Original array: ";
    print_array(arr, n);

    merge_sort(arr, n);
    cout << "Sorted array (Merge Sort): ";
    print_array(arr, n);

    insertion_sort(arr, n);
    cout << "Sorted array (Insertion Sort): ";
    print_array(arr, n);

    cout << endl;
}

// Test single element array
void test_single_element() {
    int arr[] = {1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Testing Single Element Array:\n";
    cout << "Original array: ";
    print_array(arr, n);

    merge_sort(arr, n);
    cout << "Sorted array (Merge Sort): ";
    print_array(arr, n);

    insertion_sort(arr, n);
    cout << "Sorted array (Insertion Sort): ";
    print_array(arr, n);

    cout << endl;
}

// Test already sorted array
void test_sorted_array() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Testing Already Sorted Array:\n";
    cout << "Original array: ";
    print_array(arr, n);

    merge_sort(arr, n);
    cout << "Sorted array (Merge Sort): ";
    print_array(arr, n);

    insertion_sort(arr, n);
    cout << "Sorted array (Insertion Sort): ";
    print_array(arr, n);

    cout << endl;
}

// Test reverse sorted array
void test_reverse_sorted_array() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Testing Reverse Sorted Array:\n";
    cout << "Original array: ";
    print_array(arr, n);

    merge_sort(arr, n);
    cout << "Sorted array (Merge Sort): ";
    print_array(arr, n);

    insertion_sort(arr, n);
    cout << "Sorted array (Insertion Sort): ";
    print_array(arr, n);

    cout << endl;
}

// Test array with all elements the same
void test_identical_elements_array() {
    int arr[] = {7, 7, 7, 7, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Testing Array with Identical Elements:\n";
    cout << "Original array: ";
    print_array(arr, n);

    merge_sort(arr, n);
    cout << "Sorted array (Merge Sort): ";
    print_array(arr, n);

    insertion_sort(arr, n);
    cout << "Sorted array (Insertion Sort): ";
    print_array(arr, n);

    cout << endl;
}

// Test large random array
void test_large_random_array() {
    const int n = 1000;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 1000;  // Random numbers between 0 and 999
    }

    cout << "Testing Large Random Array (Size = 1000):\n";
    cout << "Original array: [First 10 elements shown] ";
    print_array(arr, 10);  // Only print first 10 for brevity

    merge_sort(arr, n);
    cout << "Sorted array (Merge Sort): [First 10 elements shown] ";
    print_array(arr, 10);

    insertion_sort(arr, n);
    cout << "Sorted array (Insertion Sort): [First 10 elements shown] ";
    print_array(arr, 10);

    cout << endl;
}

// Test array with negative numbers
void test_array_with_negatives() {
    int arr[] = {-3, -1, -7, 2, 8, 0, -2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Testing Array with Negative Numbers:\n";
    cout << "Original array: ";
    print_array(arr, n);

    merge_sort(arr, n);
    cout << "Sorted array (Merge Sort): ";
    print_array(arr, n);

    insertion_sort(arr, n);
    cout << "Sorted array (Insertion Sort): ";
    print_array(arr, n);

    cout << endl;
}

// Test array with duplicates
void test_array_with_duplicates() {
    int arr[] = {5, 3, 8, 5, 2, 3, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Testing Array with Duplicates:\n";
    cout << "Original array: ";
    print_array(arr, n);

    merge_sort(arr, n);
    cout << "Sorted array (Merge Sort): ";
    print_array(arr, n);

    insertion_sort(arr, n);
    cout << "Sorted array (Insertion Sort): ";
    print_array(arr, n);

    cout << endl;
}

int main() {
    // Run all test cases
    test_empty_array();
    test_single_element();
    test_sorted_array();
    test_reverse_sorted_array();
    test_identical_elements_array();
    test_large_random_array();
    test_array_with_negatives();
    test_array_with_duplicates();

    return 0;
}
