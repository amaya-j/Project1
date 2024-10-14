# Project 1: Sorting Algorithms Implementation and Analysis

## Project Overview

This project focuses on implementing three common sorting algorithms: Insertion Sort, Merge Sort, and Quicksort, along with two variants of Quicksort (Improved Quicksort and Randomized Quicksort). The goal is to explore how these algorithms differ in terms of performance, memory consumption, and other aspects of their behavior on different input sizes.

Contributors: Amaya Joshi, Omar Perez, Aissatou Barry

## Project Structure

The project directory consists of the following files:

`sorting.hpp`: Contains the declarations of the sorting functions.

`sorting.cpp`: Contains the implementations of Insertion Sort, Merge Sort, Quicksort, Improved Quicksort, and Randomized Quicksort.

`mytests.cpp`: A test file that contains test cases for each sorting algorithm, verifying correctness using various input cases (regular, empty, single element, sorted, and reverse sorted arrays).

`Makefile`: A file that automates the compilation of the project, including the testing suite.

----------------------------------------------------------

- In-place Sorting for Quicksort: Quicksort and its variants were implemented as in-place sorting algorithms to avoid unnecessary memory consumption, in contrast to Merge Sort, which returns a newly allocated sorted array.
- Improved Quicksort (Median-of-Three): To improve performance in cases where the pivot selection might be suboptimal, we implemented the median-of-three strategy. For the middle element, we decided to use the element at index n/2 of the array.
- Randomized Quicksort: In the randomized version of Quicksort, we select a random element as the pivot to avoid the worst-case scenario that occurs when the input array is already sorted or reverse sorted.
- Memory Allocation in Merge Sort: Merge Sort was implemented using dynamic memory allocation for the merged halves. This choice allows for flexibility but increases memory usage.
Group Challenges
- Handling Memory in Merge Sort: Managing memory in the Merge Sort function was challenging because of the need to dynamically allocate memory for the merged result, and we had to be diligent about freeing this memory to avoid leaks.
- Testing on Large Input Sizes: Running tests on very large input sizes (up to 100,000 elements) took longer than expected, especially with Merge Sort due to its memory consumption, which required careful performance analysis.
Individual Reflection

## Amaya Joshi
For this project, my primary contributions were the implementation of the Insertion Sort and Merge Sort algorithms and the creation of extensive test cases to ensure correctness for each sorting algorithm. A challenge I faced was handling the dynamic memory allocation in Merge Sort while ensuring the original array wasn’t overwritten unexpectedly. Debugging this part of the project required careful attention to memory management.

## Known Issues
`Memory Usage in Merge Sort`: While functional, Merge Sort consumes a significant amount of memory when sorting large input sizes due to the additional memory allocations made for the left and right halves. Optimizing memory usage could be a future improvement.

`Performance of Quicksort on Small Arrays`: Quicksort, while efficient for large inputs, sometimes shows poorer performance on very small arrays compared to Insertion Sort, due to the overhead of recursion and partitioning.

## Additional Information
`Improved Quicksort Pivot Selection`: We chose to implement the median-of-three strategy for pivot selection, where we selected the first, middle, and last elements and used the median of these values as the pivot. This reduced the number of comparisons needed to partition the array in some cases.

`Performance Considerations`: The C++ std::sort() function was included in the performance tests, and it consistently outperformed our custom implementations due to its optimized hybrid sorting algorithm (which uses IntroSort, a combination of Quicksort, HeapSort, and Insertion Sort).


## Performance Analysis
For the performance analysis, we generated random integer sequences of sizes 10, 100, 1,000, 10,000, and 100,000. The following graph shows the runtime of each implemented algorithm on the y-axis, with the input size on the x-axis:

<img width="1022" alt="image" src="https://github.com/user-attachments/assets/1c677f01-4115-4ea9-8420-c924eee343e0">

`Insertion Sort`: Expectedly, Insertion Sort performed poorly on larger input sizes, with an O(n²) time complexity. It only performed well on small arrays (size < 100).

`Merge Sort`: Merge Sort displayed O(n log n) behavior, but its memory usage became significant for input sizes above 10,000 due to the additional arrays created during the merge step.

`Quicksort and Randomized Quicksort`: Both versions of Quicksort showed similar performance on average, with randomized Quicksort slightly outperforming the regular version due to reduced risk of encountering the worst case (O(n²)).

`Improved Quicksort`: Improved Quicksort with the median-of-three pivot selection consistently outperformed the basic Quicksort, especially on larger input sizes. The reduction in the number of comparisons helped to make partitioning more efficient.

`C++ std::sort()`: C++’s built-in std::sort() outperformed all the custom implementations due to its highly optimized hybrid sorting algorithm. It maintained O(n log n) performance and showed minimal memory overhead compared to Merge Sort.

## Explanation of Major Differences
`Merge Sort vs. Quicksort`: While Merge Sort provides stable O(n log n) performance, it requires significant memory allocation, which can slow down its performance on very large inputs. Quicksort, on the other hand, works in place and usually performs faster in practice, although it doesn't guarantee O(n log n) in the worst case.

`Improved Quicksort`: The median-of-three pivot selection significantly reduced the number of comparisons in certain cases, leading to faster partitioning and improved overall performance.

## Conclusion

This project provided valuable insights into the inner workings of different sorting algorithms. While each sorting algorithm has its strengths, Quicksort (especially with improvements) generally provides the best tradeoff between speed and memory usage for large datasets. However, the standard library’s std::sort() is hard to beat due to its highly optimized hybrid approach.
