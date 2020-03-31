//
// Created by haruhi on 2020/3/31.
//

#ifndef GRAPH_SPARSEGRAPH_H
#define GRAPH_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class SparseGraph {
private:
    int n,  // vertex num
    m;  // edge num
    bool directed;  // whether the graph has direction
    vector<vector<int>> g;
public:
    SparseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for (int i = 0; i < n; i++)
            g.push_back(vector<int>());
    }

    ~SparseGraph() {}

    int V() { return this->n; }

    int E() { return this->m; }

    void addEdge(int v, int w) {
        // 允许有平行边
//        if (this->hasEdge(v, w))
//            return;

        assert(v >= 0 && v < this->n);
        assert(w >= 0 && w < this->n);

        g[v].push_back(w);
        if (v != w && !directed)
            g[w].push_back(v);

        m++;
    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < this->n);
        assert(w >= 0 && w < this->n);

        for (int i = 0; i < this->g[v].size(); i++)
            if (g[v][i] == w)
                return true;

        return false;
    }
};

#endif //GRAPH_SPARSEGRAPH_H
