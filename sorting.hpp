/**
 * File Name: sorting.hpp
 * Contributors: Amaya Joshi, Omar Perez, Aissatou Barry
 * Description: This header file contains the declarations of various sorting algorithms such 
 * as insertion sort and merge sort.
 * The definitions of these functions can be found in the corresponding sorting.cpp file.
 */


#ifndef SORTING_HPP
#define SORTING_HPP

// Insertion Sort
template <typename T>
void insertion_sort(T *arr, long n);

// Merge Sort
template <typename T>
T* merge_sort(T *arr, long n);


//quicksort
template <typename T>
void quicksort(T *arr, long n);

//partition
template <typename T>
long partition(T* arr, long n);

//random pivot
template <typename T>
void randomized_quicksort(T *arr, long n);


#endif
