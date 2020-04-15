//
// Created by haruhi on 2020/4/11.
//

#ifndef MST_UNIONFIND_H
#define MST_UNIONFIND_H

#include <iostream>
#include <cassert>

using namespace std;

// quick union
class UnionFind {
private:
    // [2, 2, 2, 3, 2, 2]   ids value   the value represent parent id index in ids
    // [0, 1, 2, 3, 4, 5]   ids index   the index can represent any thing such as vertex number or etc
    int *ids;
    int n;  // ids length
    // this array every element represent the distance between current index of element in ids and it's root
    int *height;

    int find(int x) {
        while (ids[x] != x) {
            x = ids[x];
        }
        return x;
    }

public:
    UnionFind(int n) {
        this->n = n;
        this->ids = new int[n];
        this->height = new int[n];
        for (int i = 0; i < n; i++) {
            // initialize ids,  every node's parent node is itself
            ids[i] = i;
            height[i] = 0;
        }
    }

    bool isConnected(int a, int b) {
        assert(a >= 0 && a < n);
        assert(b >= 0 && b < n);
        return find(a) == find(b);
    }

    void unionElements(int a, int b) {
        assert(a >= 0 && a < n);
        assert(b >= 0 && b < n);
        if (height[a] > height[b]) {
            ids[find(b)] = find(a);
        } else {
            ids[find(a)] = find(b);
        }
    }
};

#endif //MST_UNIONFIND_H
