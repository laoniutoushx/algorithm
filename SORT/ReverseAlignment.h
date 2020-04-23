#ifndef REVERSEALIGNMENT_H
#define REVERSEALIGNMENT_H

#include <iostream>
#include <ctime>
#include <string>
#include <cassert>
#include "SortTestHelper.h"
#include "InsertSort.h"

using namespace std;

// 逆序对
// 利用分治归并 过程 在每个归并过程中 一次性找到 小于自己的所有元素，计数
namespace ReverseAlignment
{

template <typename T>
int merge(T arr[], int l, int m, int r)
{
    int reverseAlignment = 0;

    // 辅助数组 aux
    T aux[r - l + 1];

    // 复制 arr[l ... r] to aux[0 ... r-l]
    for(int i = l; i <= r; i++){
        aux[i - l] = arr[i];
    }

    //  aux
    //  左数组左边界  左数组右边界  右数组左边界      右数组右边界
    int ls = 0,      le = m - l,  rs = m - l + 1,  re = r - l;
    int index = 0;

    while(index <= re){
        if(ls > le){
            arr[index + l] = aux[rs];
            rs++;
        }else if(rs > re){
            arr[index + l] = aux[ls];
            ls++;
        }else if(aux[ls] < aux[rs]){
            arr[index + l] = aux[ls];
            ls++;
        }else if(aux[ls] >= aux[rs]){
            reverseAlignment += re - rs + 1;
            arr[index + l] = aux[rs];
            rs++;
        }
        index++;
    }
    
    return reverseAlignment;

}

template <typename T>
int split(T arr[], int l, int r)
{
    int result = 0;
    if (l >= r)
        return 0;

    int mid = l + (r - l) / 2;
    result += split(arr, l, mid);
    result += split(arr, mid + 1, r);

    result += merge(arr, l, mid, r);
    return result;
}

template <typename T>
void reverseAlignment(T arr[], int n){
    int result = split(arr, 0, n - 1);
    cout << "reverseAlignment:" << result;
}

} // namespace ReverseAlignment

#endif