//
// Created by haruhi on 2020/3/31.
//

#ifndef GRAPH_SPARSEGRAPH_H
#define GRAPH_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"

using namespace std;

template<typename Weight>
class SparseGraph {
private:
    int n,  // vertex num
    m;  // edge num
    bool directed;  // whether the graph has direction
    bool *marked;
    vector<vector<Edge<Weight> *>> g;
//    vector<vector<>> g;
public:
    SparseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        this->marked = new bool[n];
        for (int i = 0; i < n; i++) {
            g.push_back(vector<Edge<Weight> *>());
            this->marked[i] = false;
        }
    }

    ~SparseGraph() {}

    int V() { return this->n; }

    int E() { return this->m; }

    void addEdge(int v, int w, Weight weight) {
        assert(v >= 0 && v < this->n);
        assert(w >= 0 && w < this->n);

        // 允许有平行边
        if (this->hasEdge(v, w))
            return;

//        g[v].push_back(w);
        g[v].push_back(new Edge<Weight>(v, w, weight));
        if (v != w && !directed)
            g[w].push_back(new Edge<Weight>(w, v, weight));

        m++;
    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < this->n);
        assert(w >= 0 && w < this->n);

        for (int i = 0; i < this->g[v].size(); i++)
            if (g[v][i]->other(v) == w)
                return true;

        return false;
    }

    // get all of the vertex that adjacent to a vertex {v}, return a point list
    vector<Edge<Weight> *> adj(int v) {
        assert(v >= 0 && v < this->n);
        return this->g[v];
    }

    void showInfo(SparseGraph &graph) {
        cout << "SparseGraph:" << endl;
        for (int v = 0; v < V(); v++) {
            SparseGraph::adjIterator it(graph, v);
            cout << "vertex " << v << ":\t";
            for (Edge<Weight> *w = it.begin(); !it.end(); w = it.next())
                cout << "(to:" << w->w() << ",wt:" << w->wt() << ")\t";
            cout << endl;
        }
        cout << endl;
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

        Edge<Weight> *begin() {
            this->index = 0;
            if (this->G.g[v].size() > 0)
                return this->G.g[v][index];
            return NULL;
        }

        Edge<Weight> *next() {
            this->index++;
            if (this->index < this->G.g[this->v].size())
                return this->G.g[this->v][this->index];
            return NULL;
        }

        bool end() {
            return this->index >= this->G.g[this->v].size();
        }
    };
};

#endif //GRAPH_SPARSEGRAPH_H
