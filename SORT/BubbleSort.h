#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <iostream>
#include <ctime>
#include <string>
#include <cassert>

using namespace std;

namespace BubbleSort
{

template <typename T>
void bubbleSort(T arr[], int n)
{
    for(int i = 0; i < n; i++){
        int minIndex = i;
        for(int j = i; j < n; j++){
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

} // namespace InsortSort

#endif