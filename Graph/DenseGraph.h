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
    bool *marked;
    vector<vector<bool>> g;
public:
    DenseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        this->marked = new bool[n];
        for (int i = 0; i < n; i++) {
            this->marked[i] = false;
            g.push_back(vector<bool>(n, false));
        }
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

        this->marked[v] = true;
        for (int i = 0; i < n; i++)
            if (this->g[v][i] && v != i && !this->marked[i]) {
                DFS(i);
                return;
            }
    }

    void showInfo(DenseGraph &graph) {
        cout << "DenseGraph:" << endl;
        cout << "  ";
        for(int x = 0; x < V(); x++)
            cout << " " << x;
        cout << endl;
        for(int x = 0; x < V(); x++){
            cout << x << "  ";
            for(int y = 0; y < V(); y++){
                cout << (int) this->g[x][y] << " ";
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

        int begin() {
            this->index = -1;
            return next();
        }

        int next() {
            for (index += 1; index < this->G.V(); index++) {
                if (this->G.g[v][index])
                    return index;
            }
            return -1;
        }

        bool end() {
            return this->index >= this->G.V();
        }
    };
};

#endif //GRAPH_DENSEGRAPH_H
