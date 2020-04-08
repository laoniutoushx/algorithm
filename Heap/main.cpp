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
#include "MinimumHeap.h"
#include "MinimumIndexHeap.h"

using namespace std;

int main() {
    int n = 30000;

    MinHeap<int> heapIndex = MinHeap<int>(n);

    for(int i = 29999; i >= 0; i--){
        heapIndex.add(i);
    }

    for(int i = 29999; i > 100; i--){
//        heapIndex.del(i);
        heapIndex.delByIndex(i);
    }

    heapIndex.show();
    return 0;
}