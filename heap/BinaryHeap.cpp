#ifndef BINARY_H
#define BINARY_H

#include <iostream>
#include <ctime>
#include <string>
#include <cassert>
#include <math.h>

using namespace std;

template<typename Item>
class MaxHeap{
    private:
        Item* data;
        int count;

        Item left(int k){
            return data[2 * k + 1];
        };

        Item right(int k){
            return data[2 * k + 2];
        };

        Item parent(int k){
            return data[(k - 1) / 2];
        };

        /**
         * 加入元素，上移
         * k data数组下标，表示当前要 shiftUp 的元素索引位置
         **/
        void shiftUp(int k){
            while(this->data[k] > parent(k) && k > 0){
                swap(this->data[k], this->data[(k - 1) / 2]);
                k = (k - 1) / 2;
            }
        }

        void printItem(Item item, int pad, int fix){
   
            for(int i = 0; i < pad; i++){
                cout << " ";
            }
            cout << item ;
            // 元素自身长度修正
            // if(item % 10 < 10){
            //     pad -= 1;
            // }
            for(int i = 0; i < pad; i++){
                cout << " ";
            }
     
        }

    public:
        MaxHeap(int capacity){
            this->data = new Item[capacity + 1];
            count = 0;
        }
        ~MaxHeap(){
            delete[] this->data;
        }

        int size(){
            return count;
        }

        bool isEmpty(){
            return count == 0;
        }

        void printBinaryHeap(){
            // 1.计算树高度
            int height = 0, itemNumber = size();
            while((itemNumber >>= 1) > 0){
                height++;
            }
            cout << "height:" << height << endl;

            // 2.循环创建每层数据
            // 2.1 最底层树的数量为 2 的 height 次方 - 1
            int maxLeafLength = pow(2, height + 2) - 1;
            // 2.2 当前层元素间隔
            int currentLevelPaddingLength = (maxLeafLength - 1) / 2;

            for(int i = 0, index = 0 /*元素数组计数*/; i <= height; i++){
                // 2.3 开始打印每行
                int currentLevelItemNum = pow(2, i);
                while(currentLevelItemNum-- > 0 && index < size()){
                    printItem(this->data[index++], currentLevelPaddingLength,  (height + 1 - i));
                }
                // 2.4 计算下一层 padding
                currentLevelPaddingLength = (currentLevelPaddingLength - 1) / 2;
                cout << endl;
            }
        }

        void insert(Item item){
            this->data[count] = item;
            this->shiftUp(count);
            count++;
        }
};

int main(){
    MaxHeap<int> maxheap = MaxHeap<int>(100);

    srand(time(NULL));

    for(int i = 0; i < 60; i++){
        maxheap.insert(rand() % 90 + 10);
    }       

    maxheap.printBinaryHeap();
    cout << maxheap.size() << endl;
    return 0;
}

#endif