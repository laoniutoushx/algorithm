#ifndef BINARY_H
#define BINARY_H

#include <iostream>
#include <ctime>
#include <string>
#include <cassert>

using namespace std;

template<typename Item>
class MaxHeap{
    private:
        Item* data;
        int count;

        /**
         * 加入元素，上移
         * k data数组下标，表示当前要 shiftUp 的元素索引位置
         **/
        void shiftUp(int k){
            
        }

    public:
        MaxHeap(int capacity){
            data = new Item[capacity + 1];
            count = 0;
        }
        ~MaxHeap(){
            delete[] data;
        }

        int size(){
            return count;
        }

        bool isEmpty(){
            return count == 0;
        }

        void insert(Item item){

        }
};

int main(){
    MaxHeap<int> maxheap = MaxHeap<int>(100);
    cout << maxheap.size() << endl;
}

#endif