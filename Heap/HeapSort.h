/*
 * @Author: your name
 * @Date: 2020-03-19 21:46:58
 * @LastEditTime: 2020-03-23 19:53:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm\Heap\HeapSort.h
 */
#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <iostream>
#include <ctime>
#include <string>
#include <cassert>
#include <math.h>
#include "BinaryHeap.h"

using namespace std;

namespace HeapSort
{

/**
 * @description: a simple way to let a random arrary became a binary Heap
 * @param {type} 
 * @return: 
 */
template <typename T>
MaxHeap<T> heapify(T arr[], int n)
{
    // 1. make a random array become Heap array
    MaxHeap<T> maxheap = MaxHeap<T>(n);
    for (int i = 0; i < n; i++)
    {
        maxheap.insert(arr[i]);
    }
    return maxheap;
}

/**
 * 堆化 II
 * @description: 从第一个不是叶子节点的数组元素开始， shiftdown
 * @param {type} 
 * @return: 
 */
template <typename T>
MaxHeap<T> heapifyII(T arr[], int n)
{
    MaxHeap<T> maxheap = MaxHeap<T>(n);
    maxheap.assign(arr, n);

    // 获取第一个有 子节点的 父节点
    int parentIndex = (maxheap.size() - 1 - 1) / 2;
    while(parentIndex >= 0){
        maxheap.shiftDown(parentIndex);
        parentIndex--;
    }


    return maxheap;
}

template <typename T>
T *heapSort(T items[], int n)
{
    MaxHeap<T> maxheap = heapifyII(items, n);
    T *arr = new T[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = maxheap.extractMax();
    }

    return arr;
}

void test()
{
    MaxHeap<int> maxheap = MaxHeap<int>(100);

    srand(time(NULL));

    for (int i = 0; i < 24; i++)
    {
        maxheap.insert(rand() % 90 + 10);
    }

    maxheap.printBinaryHeap();

    cout << endl;
    cout << "size:" << maxheap.size() << endl;

    for (int i = 15; i > 0; i--)
    {
        cout << maxheap.extractMax() << endl;
        maxheap.printBinaryHeap();
    }
}

} // namespace HeapSort

#endif