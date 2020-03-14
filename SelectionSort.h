#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <iostream>
#include <ctime>
#include <string>
#include <cassert>

using namespace std;

namespace SelectionSort
{

template <typename T>
void selectionSort(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

} // namespace InsortSort

#endif