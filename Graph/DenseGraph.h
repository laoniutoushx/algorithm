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
    m;  // edge num
    bool directed;  // whether the edge has direction
    vector<vector<bool>> g;
public:
    DenseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for (int i = 0; i < n; i++)
            g.push_back(vector<bool>(n, false));
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
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

        return this->g[v][w];
    }

    //
    vector<int> adj(int v) {
        assert(v >= 0 && v < n);
        vector<int> ret = vector<int>();
        for (int i = 0; i < n; i++) {
            if (this->g[v][i])
                ret.push_back(i);
            else if (this->g[i][v])
                ret.push_back(i);
        }
        return ret;
    }

    // deep first search
    void DFS(int v) {
        assert(v >= 0 && v < this->n);

        cout << v << endl;

        for (int i = 0; i < n; i++)
            if (this->g[v][i] && v != i) {
                DFS(i);
                return;
            }
    }

};

#endif //GRAPH_DENSEGRAPH_H
