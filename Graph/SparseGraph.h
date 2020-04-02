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
    bool *marked;
    vector<vector<int>> g;
public:
    SparseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        this->marked = new bool[n];
        for (int i = 0; i < n; i++) {
            g.push_back(vector<int>());
            this->marked[i] = false;
        }
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

    vector<int> adj(int v) {
        assert(v >= 0 && v < this->n);
        return this->g[v];
    }

    void DFS(int v) {
        assert(v >= 0 && v < n);
        cout << v << endl;
        this->marked[v] = true;
        for (int i = 0; i < g[v].size(); i++) {
            if (!this->marked[this->g[v][i]])
                DFS(this->g[v][i]);
        }
    }

    class adjIterator {
    private:
        SparseGraph &G;
        int v;
        int index;
    public:
        adjIterator(SparseGraph &graph, int v) : G(graph) {
            this->index = 0;
            this->v = v;
        }

        int begin() {
            this->index = 0;
            if (this->G.g[v].size() > 0)
                return this->G.g[v][index];
            return -1;
        }

        int next() {
            this->index++;
            if (this->index < this->G.g[this->v].size())
                return this->G.g[this->v][this->index];
            return -1;
        }

        bool end() {
            return this->index >= this->G.g[this->v].size();
        }
    };
};

#endif //GRAPH_SPARSEGRAPH_H
