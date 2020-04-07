//
// Created by haruhi on 2020/3/31.
//

#ifndef GRAPH_DENSEGRAPH_H
#define GRAPH_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"

using namespace std;

template<typename Weight>
class DenseGraph {
private:
    int n,  // vertex num
    m;  // edge num
    bool directed;  // whether the edge has direction
    bool *marked;
    vector<vector<Edge<Weight> *>> g;
public:
    DenseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        this->marked = new bool[n];
        for (int i = 0; i < n; i++) {
            this->marked[i] = false;
            g.push_back(vector<Edge<Weight> *>(n, NULL));
        }
    }

    ~DenseGraph() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < this->g[i].size(); j++) {
                if (this->g[i][j] != NULL)
                    delete this->g[i][j];
            }
        }
    }

    int V() { return this->n; }

    int E() { return this->m; }

    /**
     * add a edge to graph
     * @param v cross axis index
     * @param w vertical axis index
     */
    void addEdge(int v, int w, int weight) {
//        if (this->hasEdge(v, w))
//            return;
        // if have duplicate edge in graph, del this edge in graph, then recreate it in graph
        if (this->hasEdge(v, w)) {
            delete g[v][w];
            if (!directed)
                delete g[w][v];
            this->m--;
        }

        this->g[v][w] = new Edge<Weight>(v, w, weight);
//        this->g[v][w] = true;
        if (!this->directed)
//            this->g[w][v] = true;
            this->g[w][v] = new Edge<Weight>(w, v, weight);
        this->m++;
    }

    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);

//        return this->g[v][w];
        return this->g[v][w] != NULL;
    }

    //
    vector<Edge<Weight> *> adj(int v) {
        assert(v >= 0 && v < n);
        vector<Edge<Weight> *> ret = vector<Edge<Weight> *>();
        for (int i = 0; i < n; i++) {
            if (this->g[v][i])
                ret.push_back(this->g[v][i]);
            else if (this->g[i][v])
                ret.push_back(this->g[i][v]);
        }
        return ret;
    }

    // deep first search
//    void DFS(int v) {
//        assert(v >= 0 && v < this->n);
//
//        cout << v << endl;
//
//        this->marked[v] = true;
//        for (int i = 0; i < n; i++)
//            if (this->g[v][i] && v != i && !this->marked[i]) {
//                DFS(i);
//                return;
//            }
//    }

    void showInfo(DenseGraph &graph) {
        cout << "DenseGraph:" << endl;
        cout << "  ";
        for (int x = 0; x < V(); x++)
            cout << " " << x;
        cout << endl;
        for (int x = 0; x < V(); x++) {
            cout << x << "  ";
            for (int y = 0; y < V(); y++) {
                if (g[x][y]) {
                    cout << this->g[x][y]->wt() << " ";
                } else {
                    cout << "NULL\t";
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    class adjIterator {
    private:
        DenseGraph &G;
        int v;
        int index;
    public:
        adjIterator(DenseGraph &graph, int v) : G(graph) {
            this->index = -1;
            this->v = v;
        }

        Edge<Weight> *begin() {
            this->index = -1;
            return next();
        }

        Edge<Weight> *next() {
            for (index += 1; index < this->G.V(); index++) {
                if (this->G.g[v][index])
                    return this->G.g[v][index];
            }
            return NULL;
        }

        bool end() {
            return this->index >= this->G.V();
        }

//        adjIterator(DenseGraph &graph, int v) : G(graph) {
//            this->index = -1;
//            this->v = v;
//        }
//
//        int begin() {
//            this->index = -1;
//            return next();
//        }
//
//        int next() {
//            for (index += 1; index < this->G.V(); index++) {
//                if (this->G.g[v][index])
//                    return index;
//            }
//            return -1;
//        }
//
//        bool end() {
//            return this->index >= this->G.V();
//        }
    };
};

#endif //GRAPH_DENSEGRAPH_H
