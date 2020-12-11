#ifndef MERGESORTBU_H
#define MERGESORTBU_H

#include <iostream>
#include <ctime>
#include <string>
#include <cassert>
#include <algorithm>
#include "SortTestHelper.h"

using namespace std;

// 自底向上

namespace MergeSortBU
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
void mergeSort(T arr[], int n)
{
    // 最底层开始循环  处理 跳跃距离 1 2 4 8， 通过 i 来分割数组
    for(int i = 1; i < n; i += i){
        // 内层数组循环整个数组，确定 两两归并数组的 边界 left mid right
        for(int l = 0, mid = l + i - 1, r = i + i - 1; 
                l < n - i;
                    l += i + i, mid += i + i, r += i + i){
            // 每次 对 arr[l...l+i-1] 与 arr[l+i...l+i+i-1] 这两部分进行归并
            merge(arr, l, mid, std::min(r, n - 1));
        }
    }


}

} // namespace MergeSort

#endif