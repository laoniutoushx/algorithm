#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <iostream>
#include <ctime>
#include <string>
#include <cassert>
#include <math.h>

template <typename Item>
class MaxHeap
{
private:
    Item *data;
    int count;

    Item left(int k)
    {
        return data[2 * k + 1];
    };

    Item right(int k)
    {
        return data[2 * k + 2];
    };

    Item parent(int k)
    {
        return data[(k - 1) / 2];
    };

    /**
             * 加入元素，上移
             * k data数组下标，表示当前要 shiftUp 的元素索引位置
             **/
    void shiftUp(int k)
    {
        while (this->data[k] > parent(k) && k > 0)
        {
            swap(this->data[k], this->data[(k - 1) / 2]);
            k = (k - 1) / 2;
        }
    }

    

    void printItem(Item item, int pad, int fix)
    {

        for (int i = 0; i < pad; i++)
        {
            cout << " ";
        }
        cout << item;
        // 元素自身长度修正
        // if(item % 10 < 10){
        //     pad -= 1;
        // }
        for (int i = 0; i < pad; i++)
        {
            cout << " ";
        }
    }

public:
    MaxHeap(int capacity)
    {
        this->data = new Item[capacity + 1];
        count = 0;
    }
    ~MaxHeap()
    {
        delete[] this->data;
    }

    // remain the properies of heap when heap top element poped
    // k is the index of element which need to be move to keep the heap properities
    void shiftDown(int k)
    {
        // 1. judge the parent whether has left child node, if not have, stop shift down
        while (k < count && 2 * k + 1 < count)
        {
            // the integer k represent the index , which current should be swap with k index,
            // default is left child node index
            int j = 2 * k + 1;
            // 2. determine whether have right node
            if (j + 1 < count && data[j] < data[j + 1])
            {
                // 3. where there is a right child node, and right child node value bigger than left child node value
                // then set j index become right child node index
                j = j + 1;
                // now index j persent the biggerst one of the children nodes index
            }
            // 4. determine whether the value of the parent node is bigger than that of the right child node
            if (data[k] > data[j])
                break;

            // 5. shift down between parent node and the biggest one of the children nodes
            swap(data[k], data[j]);
            k = j;
        }
    }

    int size()
    {
        return count;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    void printBinaryHeap()
    {
        // 1.计算树高度
        int height = 0, itemNumber = size();
        while ((itemNumber >>= 1) > 0)
        {
            height++;
        }
        cout << "height:" << height << endl;

        // 2.循环创建每层数据
        // 2.1 最底层树的数量为 2 的 height 次方 - 1
        int maxLeafLength = pow(2, height + 2) - 1;
        // 2.2 当前层元素间隔
        int currentLevelPaddingLength = (maxLeafLength - 1) / 2;

        for (int i = 0, index = 0 /*元素数组计数*/; i <= height; i++)
        {
            // 2.3 开始打印每行
            int currentLevelItemNum = pow(2, i);
            while (currentLevelItemNum-- > 0 && index < size())
            {
                printItem(this->data[index++], currentLevelPaddingLength, (height + 1 - i));
            }
            // 2.4 计算下一层 padding
            currentLevelPaddingLength = (currentLevelPaddingLength - 1) / 2;
            cout << endl;
        }
    }

    void insert(Item item)
    {
        this->data[count] = item;
        this->shiftUp(count);
        count++;
    }

    // pops up the heap top element
    Item extractMax()
    {
        if (count > 0)
        {
            Item result = data[0];
            data[0] = data[count - 1];
            count--;
            shiftDown(0);
            return result;
        }
        return 0;
    }

    Item* values(){
        return data;
    }

    void assign(Item item[], int n){
        this->data = item;
        this->count = n;
    }
};

// int main(){
//     MaxHeap<int> maxheap = MaxHeap<int>(100);

//     srand(time(NULL));

//     for(int i = 0; i < 24; i++){
//         maxheap.insert(rand() % 90 + 10);
//     }

//     maxheap.printBinaryHeap();

//     cout << endl;
//     cout << "size:" << maxheap.size() << endl;

//     for(int i = 15; i > 0; i--){
//         cout << maxheap.extractMax() << endl;
//         maxheap.printBinaryHeap();
//     }

//     return 0;
// }

#endif