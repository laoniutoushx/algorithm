//
// Created by haruhi on 2020/3/31.
//

#ifndef GRAPH_DENSEGRAPH_H
#define GRAPH_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class DenseGraph {
private:
    int n,  // vertex num
    d,  // matrix length/width
    m;  // edge num
    bool directed;  // whether the edge has direction
    vector<vector<bool>> g;
public:
    DenseGraph(int d, bool directed) {
        this->d = d;
        this->n = d * d;
        this->m = 0;
        this->directed = directed;
        for (int i = 0; i < d; i++)
            g.push_back(vector<bool>(d, false));
    }

    ~DenseGraph() {}

    int V() { return this->n; }

    int E() { return this->m; }

    /**
     * add a edge to graph
     * @param v cross axis index
     * @param w vertical axis index
     */
    void addEdge(int v, int w) {
        if (this->hasEdge(v, w))
            return;

        this->g[v][w] = true;
        if (!this->directed)
            this->g[w][v] = true;

        this->m++;
    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < d);
        assert(w >= 0 && w < d);

        return this->g[v][w];
    }
};

#endif //GRAPH_DENSEGRAPH_H
