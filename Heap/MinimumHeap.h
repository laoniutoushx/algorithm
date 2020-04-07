//
// Created by haruhi on 2020/4/7.
//

#ifndef MINIMUMHEAP_H
#define MINIMUMHEAP_H

#include <iostream>
#include <cassert>
#include <stack>
#include <vector>

using namespace std;

// min heap
template<typename Node>
class MinHeap {
private:
    Node *nodes;    // heap elements array
    int index;      // the position that next node will be placed
    int capacity;      // the heap can hold how much node, a limit num

    void shiftUp(int pos) {
        if (pos >= 0 && pos < capacity) {
            int par_pos = pos - 1 / 2;
            if (nodes[pos] < nodes[par_pos]) {
                swap(nodes[pos], nodes[par_pos]);
                shiftUp(par_pos);
            }
        }
    }

    void shiftDown(int pos) {
        if (pos < capacity && pos * 2 + 1 < capacity) {
            int left_child_pos = pos * 2 + 1;


            int cur_min_val_pos = left_child_pos;

            if(left_child_pos + 1 < capacity && nodes[left_child_pos + 1] < nodes[left_child_pos]){
                cur_min_val_pos = left_child_pos + 1;
            }

            if (nodes[pos] < nodes[cur_min_val_pos])
                return;

            swap(nodes[cur_min_val_pos], nodes[pos]);
            shiftDown(cur_min_val_pos);
        }
    }

    void print(vector<int> &v) {
        for (int &i : v) {
            if(i <= index)
                cout << nodes[i] << " ";
        }
        cout << endl;
    }

public:
    MinHeap(int n) {
        this->index = -1;
        this->capacity = n;
        this->nodes = new Node[n];
    }

    // get top element in heap
    Node pop() {
        assert(index >= 0);

        Node ret = nodes[0];            // remember first element in heap array
        swap(nodes[index], nodes[0]);   // swap end element and first element in heap array
        index--;                        // index --
        shiftDown(0);                   // keep heap property
        return ret;
    }

    void add(Node node) {
        index++;                        // index ++

        // put the element in array end, then shift up, find the appropriate position
        assert(index < capacity);

        nodes[index] = node;            // put the node to heap array[index]
        shiftUp(index);                 // keep heap property
    }

    void show() {
        // level sequence traversal
        cout << "Min Heap:" << endl;

        vector<int> par_s;

        int par_pos = 0;
        par_s.push_back(par_pos);
        while (!par_s.empty()) {
            print(par_s);

            vector<int> temp_par;

            for (int par_ : par_s) {
                par_pos = par_;

                int left_child_pos = par_pos * 2 + 1;
                int right_child_pos = par_pos * 2 + 2;
                if (left_child_pos < capacity)
                    temp_par.push_back(left_child_pos);


                if (right_child_pos < capacity)
                    temp_par.push_back(right_child_pos);
            }

            par_s = temp_par;
        }


    }
};

#endif //MINIMUMHEAP_H
