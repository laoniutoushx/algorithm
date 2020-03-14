#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <iostream>
#include <ctime>
#include <string>
#include <cassert>

using namespace std;

namespace ShellSort
{

template <typename T>
void shellSort(T arr[], int n)
{
    int h = 1;
    // 处理递增数列
    while(h < n / 3)
        h = h * 3 + 1;

    // 插入排序
    while(h >= 1){
        for(int i = h; i < n; i++){
            T curValue = arr[i];
            int j;
            for(j = i; j >= h; j -= h){
                if(curValue < arr[j - h]){
                    arr[j] = arr[j - h];
                }else{
                    break;
                }
            }
            arr[j] = curValue;
        }
        h = h / 3;
    }
}

} // namespace InsortSort

#endif