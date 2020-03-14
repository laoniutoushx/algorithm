#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <ctime>
#include <string>
#include <cassert>
#include "SortTestHelper.h"
#include "InsertSort.h"

using namespace std;

// 自顶向下

namespace MergeSort
{

template <typename T>
void merge(T arr[], int l, int mid, int r)
{
    // 原址归并  arr[i..mid] ~ arr[mid+1..r]
    int i = l, j = mid + 1;
    T aux[r - l + 1]; // 辅助数组
    for (int k = l; k <= r; k++)
    {
        aux[k - l] = arr[k];
    }

    for (int k = l; k <= r; k++)
    {
        if (i > mid)
        { // 左边数组 超出边界，  则直接将右边数组按序赋值给 arr
            arr[k] = aux[j - l];
            j++;
        }
        else if (j > r)
        { // 右边数组 超出边界，  则直接将左边数组按序复制给 arr
            arr[k] = aux[i - l];
            i++;
        }
        else if (aux[i - l] < aux[j - l])
        { // 左右数组 index 均未越界， 则比较 左右当前 index 所在值大小，按代大小 复制到 arr
            arr[k] = aux[i - l];
            i++;
        }
        else
        {
            arr[k] = aux[j - l];
            j++;
        }
    }
}

template <typename T>
void seperate(T arr[], int l, int r)
{
    // 第二个优化点  在一点数量的输入集中， 插入排序性能要优于归并排序，此处设置一个 字数组临界点，转换为插入排序
    // if (l >= r)
    // {
    //     return;
    // }
    if( r - l <= 15){
        return InsortSort::insertSortArrayBoundary(arr, l, r);
    }

    int mid = l + (r - l) / 2; //   (0 + 3) / 2 = 1    (0 + 1) / 2 = 0;

    seperate(arr, l, mid);
    seperate(arr, mid + 1, r);

    // 第一个优化点   [由于 arr[l, mid] 与 arr[mid + 1, r] 已经各自有序， 
    // 故对于近乎有序的数组输入来说， 此处可 判断 arr[mid] > arr[mid + 1] 来判断是否需要归并 ]
    if(arr[mid] > arr[mid + 1])
        merge(arr, l, mid, r);
}

template <typename T>
void mergeSort(T arr[], int n)
{
    seperate(arr, 0, n - 1);
}

} // namespace MergeSort

#endif