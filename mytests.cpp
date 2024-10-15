//==============================================================
// File Name: mytests.cpp
// Developer Names: Aisha Berry, Max Bonsteel, Huy Phan
// Date: 10/14/2024
// About: mytests.cpp contains test cases to verify that each
// sorting algorithm (insertion_sort, merge_sort, quicksort,
// improved_quicksort, and randomized_quicksort) correctly sorts
//different types of input arrays. 
//==============================================================
#include "sorting.hpp"
#include <iostream>
#include "sorting.cpp"
#include <cassert>
using namespace std;


template <typename T>
void print_array(T *arr, long n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//==============================================================
// Test the empty array
// Parameter: None
// Return: None
//==============================================================
void test_empty_array() {
    int arr[] = {};
    long n = sizeof(arr) / sizeof(arr[0]);

    cout << "Testing Empty Array:\n";
    cout << "Original array: ";
    print_array(arr, n);

    merge_sort(arr, n);
    cout << "Sorted array (Merge Sort): ";
    print_array(arr, n);

    insertion_sort(arr, n);
    cout << "Sorted array (Insertion Sort): ";
    print_array(arr, n);

    quicksort(arr, n);
    cout << "Sorted array (Quicksort): ";
    print_array(arr, n);

    improved_quicksort(arr, n);
    cout << "Sorted array (Improved Quicksort): ";
    print_array(arr, n);

    randomized_quicksort(arr, n);
    cout << "Sorted array (Randomized Quicksort): ";
    print_array(arr, n);
    
    cout << endl;
}

//==============================================================
// Test single element array
// Parameter: None
// Return: None
//==============================================================
void test_single_element() {
    int arr[] = {1};
    long n = sizeof(arr) / sizeof(arr[0]);

    cout << "Testing Single Element Array:\n";
    cout << "Original array: ";
    print_array(arr, n);

    merge_sort(arr, n);
    cout << "Sorted array (Merge Sort): ";
    print_array(arr, n);

    insertion_sort(arr, n);
    cout << "Sorted array (Insertion Sort): ";
    print_array(arr, n);

    quicksort(arr, n);
    cout << "Sorted array (Quicksort): ";
    print_array(arr, n);

    improved_quicksort(arr, n);
    cout << "Sorted array (Improved Quicksort): ";
    print_array(arr, n);

    randomized_quicksort(arr, n);
    cout << "Sorted array (Randomized Quicksort): ";
    print_array(arr, n);
    
    cout << endl;
}

//==============================================================
// Test already sorted array
// Parameter: None
// Return: None
//==============================================================
void test_sorted_array() {
    int arr[] = {1, 2, 3, 4, 5};
    long n = sizeof(arr) / sizeof(arr[0]);

    cout << "Testing Already Sorted Array:\n";
    cout << "Original array: ";
    print_array(arr, n);

    merge_sort(arr, n);
    cout << "Sorted array (Merge Sort): ";
    print_array(arr, n);

    insertion_sort(arr, n);
    cout << "Sorted array (Insertion Sort): ";
    print_array(arr, n);

    quicksort(arr, n);
    cout << "Sorted array (Quicksort): ";
    print_array(arr, n);

    improved_quicksort(arr, n);
    cout << "Sorted array (Improved Quicksort): ";
    print_array(arr, n);

    randomized_quicksort(arr, n);
    cout << "Sorted array (Randomized Quicksort): ";
    print_array(arr, n);
    
    cout << endl;
}

//==============================================================
// Test reverse sorted array
// Parameter: None
// Return: None
//==============================================================
void test_reverse_sorted_array() {
    int arr[] = {5, 4, 3, 2, 1};
    long n = sizeof(arr) / sizeof(arr[0]);

    cout << "Testing Reverse Sorted Array:\n";
    cout << "Original array: ";
    print_array(arr, n);

    merge_sort(arr, n);
    cout << "Sorted array (Merge Sort): ";
    print_array(arr, n);

    insertion_sort(arr, n);
    cout << "Sorted array (Insertion Sort): ";
    print_array(arr, n);

    quicksort(arr, n);
    cout << "Sorted array (Quicksort): ";
    print_array(arr, n);

    improved_quicksort(arr, n);
    cout << "Sorted array (Improved Quicksort): ";
    print_array(arr, n);

    randomized_quicksort(arr, n);
    cout << "Sorted array (Randomized Quicksort): ";
    print_array(arr, n);
    
    cout << endl;
}

//==============================================================
// Test array with all elements the same
// Parameter: None
// Return: None
//==============================================================
void test_identical_elements_array() {
    int arr[] = {7, 7, 7, 7, 7};
    long n = sizeof(arr) / sizeof(arr[0]);

    cout << "Testing Array with Identical Elements:\n";
    cout << "Original array: ";
    print_array(arr, n);

    merge_sort(arr, n);
    cout << "Sorted array (Merge Sort): ";
    print_array(arr, n);

    insertion_sort(arr, n);
    cout << "Sorted array (Insertion Sort): ";
    print_array(arr, n);

    quicksort(arr, n);
    cout << "Sorted array (Quicksort): ";
    print_array(arr, n);

    improved_quicksort(arr, n);
    cout << "Sorted array (Improved Quicksort): ";
    print_array(arr, n);

    randomized_quicksort(arr, n);
    cout << "Sorted array (Randomized Quicksort): ";
    print_array(arr, n);

    cout << endl;
}

//==============================================================
// Test large random array
// Parameter: None
// Return: None
//==============================================================
void test_large_random_array() {
    const long n = 1000;
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

    quicksort(arr, n);
    cout << "Sorted array (QuickSort): [First 10 elements shown] ";
    print_array(arr, 10);

    improved_quicksort(arr, n);
    cout << "Sorted array (Improved QuickSort): [First 10 elements shown] ";
    print_array(arr, 10);

    randomized_quicksort(arr, n);
    cout << "Sorted array (Randomized QuickSort): [First 10 elements shown] ";
    print_array(arr, 10);

    cout << endl;
}

//==============================================================
// Test array with negative numbers
// Parameter: None
// Return: None
//==============================================================
void test_array_with_negatives() {
    int arr[] = {-3, -1, -7, 2, 8, 0, -2};
    long n = sizeof(arr) / sizeof(arr[0]);

    cout << "Testing Array with Negative Numbers:\n";
    cout << "Original array: ";
    print_array(arr, n);

    merge_sort(arr, n);
    cout << "Sorted array (Merge Sort): ";
    print_array(arr, n);

    insertion_sort(arr, n);
    cout << "Sorted array (Insertion Sort): ";
    print_array(arr, n);

    quicksort(arr, n);
    cout << "Sorted array (Quicksort): ";
    print_array(arr, n);

    improved_quicksort(arr, n);
    cout << "Sorted array (Improved Quicksort): ";
    print_array(arr, n);

    randomized_quicksort(arr, n);
    cout << "Sorted array (Randomized Quicksort): ";
    print_array(arr, n);

    cout << endl;
}

//==============================================================
// Test array with duplicates
// Parameter: None
// Return: None
//==============================================================
void test_array_with_duplicates() {
    int arr[] = {5, 3, 8, 5, 2, 3, 5, 9};
    long n = sizeof(arr) / sizeof(arr[0]);

    cout << "Testing Array with Duplicates:\n";
    cout << "Original array: ";
    print_array(arr, n);

    merge_sort(arr, n);
    cout << "Sorted array (Merge Sort): ";
    print_array(arr, n);

    insertion_sort(arr, n);
    cout << "Sorted array (Insertion Sort): ";
    print_array(arr, n);

    quicksort(arr, n);
    cout << "Sorted array (Quicksort): ";
    print_array(arr, n);

    improved_quicksort(arr, n);
    cout << "Sorted array (Improved Quicksort): ";
    print_array(arr, n);

    randomized_quicksort(arr, n);
    cout << "Sorted array (Randomized Quicksort): ";
    print_array(arr, n);

    cout << endl;
}

//==============================================================
// Main function to run all tests
//==============================================================
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
