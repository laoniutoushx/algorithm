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
        assert(!visited[v]);
        visited[v] = true;

        typename Graph::adjIterator adj(G, v);
        for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next()) {
            if (!visited[e->other(v)])
                pq.add(*e);
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
        handler(0);

        // get the min edge
        while (!pq.isEmpty()) {
            Edge<Weight> minEdge = pq.pop();

            // judge whether the two vertexes on the minEdge is different side(color)
            if (visited[minEdge.v()] == visited[minEdge.w()]) {
                continue;
            } else {
                mst.push_back(minEdge);
                if (visited[minEdge.v()]) {
                    handler(minEdge.w());
                } else {
                    handler(minEdge.v());
                }
            }
        }

        cout << "MST: " << endl;
        for (int i = 0; i < mst.size(); i++) {
            cout << mst[i] << endl;
        }
    };
};

#endif //GRAPH_LAZYPRIMMST_H
