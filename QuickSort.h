#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <ctime>
#include <string>
#include <cassert>
#include "SortTestHelper.h"
#include "InsertSort.h"

using namespace std;

namespace QuickSort
{

// 三路快速排序   l 左边界 r 有边界 array.length
template <typename T>
void threeWaySort(T arr[], int l, int r)
{
    if (l >= r)
        return;

    // 随机一个 index， 防止 有序输入 退化为 N² 算法
    swap(arr[l], arr[rand() % (r - l) + l]);

    // 需要维持的状态
    // [44, 3, 7, 11, 15, 18, 44, 44, 44, 44, 15, 18, 87, 32, 47, 44, 99, 120, 111]
    //  k                →lt                  →i                      gt←               sorting
    //  k
    //  lt  i                                                                      gt   initialize
    int k = l, lt = l, i = l + 1, gt = r;
    while (i < gt)
    {
        if (arr[i] < arr[k])
        {
            lt++;
            i++;
        }
        else if (arr[i] == arr[k])
        {
            i++;
        }
        else if (arr[i] > arr[k])
        {
            gt--;
            swap(arr[i], arr[gt]);
        }
    }
    swap(arr[k], arr[lt]);

    threeWaySort(arr, k, lt);
    threeWaySort(arr, gt, r);
}

template <typename T>
int partitionII(T arr[], int l, int r)
{
    // 随机一个 index， 防止 有序输入 退化为 N² 算法
    swap(arr[l], arr[rand() % (r - l) + l]);

    // [7, 1, 1, 1, 2, 2, 3, 3, 3, 3, 8]    防止出现此种情况
    //　从左右两边同时向中间遍历
    // 左边 小于 arr[k], 右边大于 arr[k]， 如此保证 等于 arr[k] 的元素 均匀分布于 数组两边
    // [48, 2, 3, 5, 6, 54, 58, 77, 23, 24, 67, 18, 99, 120, 130, 133, 156, 214]
    //   k         → i                              j ←
    int k = l, i = l + 1, j = r - 1;
    while (true)
    {
        while (arr[i] < arr[k])
            i++;
        while (arr[j] > arr[k])
            j--;
        if (i >= j)
            break;
        swap(arr[i++], arr[j--]);
        // 程序始终维持上述状态
    }
    swap(arr[k], arr[j]);
    return j;
}

// 此方法无法阻止 大量重复输入下  退化为 N² 算法
// [7, 1, 1, 1, 2, 2, 3, 3, 3, 3, 8]    防止出现此种情况
template <typename T>
int partition(T arr[], int l, int r)
{
    // 随机一个 index， 防止 有序输入 退化为 N² 算法
    swap(arr[l], arr[rand() % (r - l) + l]);

    // [48, 2, 3, 5, 6, 54, 58, 77, 23, 24, 67, 18]
    //  k            j               i
    // i 当前元素
    // j 小于比较值的 最后一个边界， 大于 arr[k] 与 小于arr[k] 的分界索引 index
    // k 比较值索引
    int i = l + 1, j = l, k = l;
    for (; i < r; i++)
    {
        if (arr[i] < arr[k])
        {
            swap(arr[j + 1], arr[i]);
            j++;
        }
    }
    swap(arr[k], arr[j]); // 将比较值 放置到 j 的位置
    return j;
}

template <typename T>
void sort(T arr[], int l, int r)
{
    // if(l >= r){
    //     return;
    // }
    if (r - l <= 15)
    {
        return InsortSort::insertSortArrayBoundary(arr, l, r - 1);
    }

    int mid = partitionII(arr, l, r);
    sort(arr, l, mid);
    sort(arr, mid + 1, r);
}

template <typename T>
void quickSort(T arr[], int n)
{
    srand(time(NULL));
    // sort(arr, 0, n);
    threeWaySort(arr, 0, n);
}

} // namespace QuickSort

#endif