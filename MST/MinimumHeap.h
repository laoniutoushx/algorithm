//
// Created by haruhi on 2020/4/7.
//

#ifndef MINIMUMHEAP_H
#define MINIMUMHEAP_H

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// min heap
template<typename Node>
class MinHeap {
private:
    Node *nodes;    // heap elements array
    int limit;      // the position that next node will be placed, it also represents the array boundary
    int length;   // the heap array initialize length

    void shiftUp(int pos) {
        if (pos > 0 && pos <= limit) {
            int par_pos = (pos - 1) / 2;
            if (nodes[pos] < nodes[par_pos]) {
                swap(nodes[pos], nodes[par_pos]);
                shiftUp(par_pos);
            }
        }
    }

    void shiftDown(int pos) {
        if (pos < limit && pos * 2 + 1 < limit) {
            int left_child_pos = pos * 2 + 1;
            int right_child_pos = left_child_pos + 1;

            int cur_min_val_pos = left_child_pos;

            if (right_child_pos < limit && nodes[right_child_pos] < nodes[left_child_pos]) {
                cur_min_val_pos = right_child_pos;
            }

            if (nodes[pos] < nodes[cur_min_val_pos])
                return;

            swap(nodes[cur_min_val_pos], nodes[pos]);
            shiftDown(cur_min_val_pos);
        }
    }

    // return index of element node in heap array nodes
    int find(Node node) {
        for (int i = 0; i < limit; i++) {
            if (nodes[i] == node) {
                return i;
            }
        }
        return -1;
    }

    void print(vector<int> &v) {
        for (int &i : v) {
            if (i < limit)
                cout << nodes[i] << " ";
        }
        cout << endl;
    }

public:
    MinHeap(int n) {
        this->limit = 0;
        this->length = n;
        this->nodes = new Node[n];
    }

    // get top element in heap
    Node pop() {
        assert(limit >= 0);

        Node ret = nodes[0];            // remember first element in heap array
        limit--;                        // limit --
        swap(nodes[limit], nodes[0]);   // swap end element and first element in heap array
        shiftDown(0);                   // keep heap property
        return ret;
    }

    void add(Node node) {
        // put the element in array end, then shift up, find the appropriate position
        assert(limit < length);

        nodes[limit] = node;            // put the node to heap array[limit]
        shiftUp(limit);                 // keep heap property
        limit++;                        // limit ++
    }

    // someone who want to del node, use this method
    void del(Node node) {
        int del_index = find(node);
        if (del_index >= 0 && del_index < limit) {
            limit--;
            swap(nodes[limit], nodes[del_index]);
            shiftUp(del_index);
            shiftDown(del_index);
        }
    }

    // someone who want to del the ith node in nodes, it equals nodes[i]
    void delByIndex(int del_index) {
        if (del_index >= 0 && del_index < limit) {
            limit--;
            swap(nodes[limit], nodes[del_index]);
            shiftUp(del_index);
            shiftDown(del_index);
        }
    }

    // update node by index
    void update(int udp_index, Node udp_node) {
        if (udp_index >= 0 && udp_index < limit) {
            nodes[udp_index] = udp_node;
            shiftUp(udp_index);
            shiftDown(udp_index);
        }
    }

    bool isEmpty() {
        return limit == 0;
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

#endif //MINIMUMHEAP_H
