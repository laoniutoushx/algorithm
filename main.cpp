/*
 * @Author: your name
 * @Date: 2020-03-19 21:46:58
 * @LastEditTime: 2020-03-23 19:54:40
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm\main.cpp
 */
#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "InsertSort.h"
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "MergeSortBU.h"
#include "QuickSort.h"
#include "ReverseAlignment.h"
#include "heap/HeapSort.h"

using namespace std;

const int SAMPLE = 1000000;

int main()
{
     int n = 100;
    // int* arr = SortTestHelper::generateNearlyOrderedArray(n, 20 );
    // int* arr = SortTestHelper::generateRandomArray(n, 0, 20);
    // int* arr1 = SortTestHelper::copyIntArray(arr, n);
    // int* arr2 = SortTestHelper::copyIntArray(arr, n);
    // int* arr3 = SortTestHelper::copyIntArray(arr, n);
    // int* arr4 = SortTestHelper::copyIntArray(arr, n);
    // int* arr5 = SortTestHelper::copyIntArray(arr, n);
    // int* arr6 = SortTestHelper::copyIntArray(arr, n);

    // SortTestHelper::testSort("Selection Sort", SelectionSort::selectionSort, arr, n);
    // SortTestHelper::testSort("Insert Sort", InsortSort::insertSortFastVersion, arr1, n);
    // SortTestHelper::testSort("Bubble Sort", BubbleSort::bubbleSort, arr2, n);
    // SortTestHelper::testSort("Shell Sort", ShellSort::shellSort, arr3, n);
    // SortTestHelper::testSort("Merge Sort", MergeSort::mergeSort, arr4, n);
    // SortTestHelper::testSort("Merge Sort BU", MergeSortBU::mergeSort, arr5, n);
    // SortTestHelper::testSort("Quick Sort", QuickSort::quickSort, arr6, n);

    // SortTestHelper::printArray(arr6, n);
    // delete[] arr;
    // delete[] arr1;

    // int arr[4] = {8, 7, 6, 5};

    // ReverseAlignment::reverseAlignment(arr, 4);

    int* arr = SortTestHelper::generateRandomArray(n, 0, n);
    arr = HeapSort::heapSort(arr, n);
    SortTestHelper::printArray(arr, n);
    return 0;
}