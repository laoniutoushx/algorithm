#ifndef INSERTSORT_H
#define INSERTSORT_H

#include <iostream>
#include <ctime>
#include <string>
#include <cassert>

using namespace std;

namespace InsortSort
{
template <typename T>
void insertSort(T arr[], int n)
{

    for (int i = 1; i < n; i++)
    {
        // 前面的部分  交替比较 arr[i] 与 arr[0] ~ arr[i - 1]
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
            else
                break;
        }
    }
}

template <typename T>
void insertSortFastVersion(T arr[], int n)
{

    for (int i = 1; i < n; i++)
    {
        // 前面的部分  交替比较 arr[i] 与 arr[0] ~ arr[i - 1]
        //　特别之处： 每次比较小于时，不是立即交换位置，而是 大的放到小的位置，而 当前值继续与之前的元素比较，直到遇到小于自己的，则将自己放在该位置之后，或者到达数组头部
        T curValue = arr[i];
        int j; // 保存元素 curValue 应该插入的位置
        for (j = i; j > 0; j--)
        {
            if (curValue < arr[j - 1])
                arr[j] = arr[j - 1];
            else
                break;
        }
        arr[j] = curValue;
    }
}

// 一定范围内排序
template <typename T>
void insertSortArrayBoundary(T arr[], int l, int r)
{
    // left  right  arr[l .... r] 区间排序

    for (int i = l; i < r; i++)
    {
        int minIndex = i + 1;
        T minValue = arr[minIndex];
        for (int k = i + 1; k > l; k--)
        {
            if (arr[k - 1] > minValue)
            {
                arr[k] = arr[k - 1];
                minIndex = k - 1;
            }
            else
            {
                break;
            }
        }
        arr[minIndex] = minValue;
    }
}

} // namespace InsortSort

#endif