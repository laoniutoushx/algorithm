//
// Created by haruhi on 2020/4/7.
//

#ifndef MINIMUMINDEXHEAP_H
#define MINIMUMINDEXHEAP_H

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// min heap
template<typename Node>
class MinIndexHeap {
private:
    Node *nodes;    // heap elements array
    int limit;      // the position that next node will be placed, it also represents the array boundary
    // now it represents array indexes limit
    int length;   // the heap array initialize length
    // nodes    [1, 3, 2, 7, 5, 8];   element array
    // indexes  [0, 1, 2, 3, 4, 5];   index of ele in nodes
    int *indexes;    // the array indexes reflect to array node's index

    // handler the indexes array, only move the pointer which point to nodes element
    void shiftUp(int pos) {
        if (pos > 0 && pos <= limit) {
            int par_pos = (pos - 1) / 2;
            if (nodes[indexes[pos]] < nodes[indexes[par_pos]]) {
                swap(indexes[pos], indexes[par_pos]);
                shiftUp(par_pos);
            }
        }
    }

    void shiftDown(int pos) {
        if (pos < limit && pos * 2 + 1 < limit) {
            int left_child_pos = pos * 2 + 1;
            int right_child_pos = left_child_pos + 1;

            int cur_min_val_pos = left_child_pos;

            if (right_child_pos < limit && nodes[indexes[right_child_pos]] < nodes[indexes[left_child_pos]]) {
                cur_min_val_pos = right_child_pos;
            }

            if (nodes[indexes[pos]] < nodes[indexes[cur_min_val_pos]])
                return;

            // swap indexes pointer position, to remain heap nature
            swap(indexes[cur_min_val_pos], indexes[pos]);
            shiftDown(cur_min_val_pos);
        }
    }

    // return index of element node in heap array nodes
    int find(Node node) {
        for (int i = 0; i < limit; i++) {
            if (nodes[indexes[i]] == node) {
                return i;
            }
        }
        return -1;
    }

    void print(vector<int> &v) {
        for (int &i : v) {
            if (i < limit)
                cout << nodes[indexes[i]] << " ";
        }
        cout << endl;
    }

public:
    MinIndexHeap(int n) {
        this->limit = 0;
        this->length = n;
        this->nodes = new Node[n];
        this->indexes = new int[n];
        for (int i = 0; i < n; i++) {
            this->indexes[i] = i;
        }
    }

    // add element
    void add(Node node) {
        // put the element in array end, then shift up, find the appropriate position
        assert(limit < length);

        nodes[indexes[limit]] = node;
//        nodes[limit] = node;            // put the node to heap array[limit]
        shiftUp(limit);                 // keep heap property
        limit++;                        // limit ++
    }

    // get top element in heap
    Node pop() {
        assert(limit >= 0);

        Node ret = nodes[indexes[0]];            // remember first element in heap array
        limit--;                        // limit --
        swap(indexes[limit], indexes[0]);   // swap end element and first element in heap array
        shiftDown(0);                   // keep heap property
        return ret;
    }

    void del(Node node) {
        int del_index = find(node);
        if (del_index > 0) {
            limit--;
            swap(indexes[limit], indexes[del_index]);
            shiftUp(del_index);
            shiftDown(del_index);
        }
    }

    // someone who want to del the ith node in nodes, it equals nodes[i]
    void delByIndex(int del_index) {
        if (del_index >= 0 && del_index < limit) {
            limit--;
            swap(indexes[limit], indexes[del_index]);
            shiftUp(del_index);
            shiftDown(del_index);
        }
    }

    void showNodes() {
        for (int i = 0; i < limit; i++) {
            cout << nodes[i] << " -> ";
        }
        cout << endl;
    }

    void showIndexes() {
        for (int i = 0; i < limit; i++) {
            cout << indexes[i] << " -> ";
        }
        cout << endl;
    }

    void show() {
        // level sequence traversal
        cout << "Min Heap:" << endl;

        vector<int> par_s;

        int par_pos = 0;
        par_s.push_back(par_pos);
        while (!par_s.empty()) {
            print(par_s);

            vector<int> next_pars;

            for (int par_ : par_s) {
                par_pos = par_;

                int left_child_pos = par_pos * 2 + 1;
                int right_child_pos = left_child_pos + 1;
                if (left_child_pos < limit)
                    next_pars.push_back(left_child_pos);

                if (right_child_pos < limit)
                    next_pars.push_back(right_child_pos);
            }

            par_s = next_pars;
        }
    }
};

#endif //MINIMUMINDEXHEAP_H
