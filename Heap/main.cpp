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

using namespace std;

int main() {
    MinHeap<int> heap = MinHeap<int>(6);

    heap.add(1);
    heap.add(3);
    heap.add(2);
    heap.add(7);
    heap.add(5);
    heap.add(8);

    heap.show();

    for(int i = 4; i >= 0; i--){
        heap.pop();
        heap.show();
    }

    return 0;
}