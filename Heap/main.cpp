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
    MinIndexHeap<int> minIndexHeap = MinIndexHeap<int>(n);

    for(int i = 20; i >= 0; i--){
        heapIndex.add(i);
        minIndexHeap.add(i);
    }

    heapIndex.show();
    minIndexHeap.show();
    minIndexHeap.showNodes();
    minIndexHeap.showIndexes();

    cout << endl;
//    for(int i = 20; i > 5; i--){
////        heapIndex.del(i);
//        heapIndex.del(i);
//        minIndexHeap.del(i);
//    }
    heapIndex.del(0);
    minIndexHeap.delByIndex(20);

    heapIndex.show();
    minIndexHeap.show();
    minIndexHeap.showNodes();
    minIndexHeap.showIndexes();
    return 0;
}