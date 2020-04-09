//
// Created by haruhi on 2020/4/6.
//

#ifndef GRAPH_LAZYPRIMMST_H
#define GRAPH_LAZYPRIMMST_H

#include <iostream>
#include <cassert>
#include <stack>
#include <vector>
#include <queue>
#include "Edge.h"
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "MinimumIndexHeap.h"

using namespace std;

//  minimal spanning tree
template<typename Graph, typename Weight>
class LazyPrimMST {
private:
    Graph &G;
    bool *visited;
    vector<Edge<Weight>> mst;
    MinIndexHeap<Edge<Weight>> pq;      // priority queue
    Weight mstWeight;

    void handler(int v) {
        visited[v] = true;

        typename Graph::adjIterator adj(G, G.V());
        for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next()) {
            pq.add(*e);
        }

        // get the min edge
        Edge<Weight> *minEdge = pq.pop();
        while (minEdge->wt() > 0) {
            int other_v = minEdge->other(v);
            // judge whether another vertex on the min edge has visited
            if (visited[other_v]) {   // judge the other side vertex on the edge whether visited
                minEdge = pq.pop();
            } else {
                mst.push_back(minEdge);
                pq.clear();
                handler(other_v);
            }
        }
    }

public:
    LazyPrimMST(Graph &graph) : G(graph), pq(MinIndexHeap<Edge<Weight>>(graph.E())) {
        visited = new bool[G.V()];
        // init vertex whether visited
        for (int i = 0; i < G.V(); i++) {
            visited[i] = false;
        }
        mst.clear();

        // traversal from vertex 0;
        int v = 0;
        handler(v);

        for (int i = 0; i < mst.size(); i++) {
            cout << mst[i] << endl;
        }
    }
};

#endif //GRAPH_LAZYPRIMMST_H
