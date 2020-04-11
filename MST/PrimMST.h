//
// Created by haruhi on 2020/4/11.
//

#ifndef MST_PRIMMST_H
#define MST_PRIMMST_H

#include <iostream>
#include <cassert>
#include <vector>
#include "Edge.h"
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "MinimumIndexHeap.h"

template<typename Graph, typename Weight>
class PrimMST {
private:
    Graph &G;
    // index priority queue, every index represent a vertex in graph, value is edge weight, edge is v -> ?
    // weight   [0.1, 0.2, 0.3, 0.4, 0.6, 0.19]   minIndexHeap values
    // ipq      [  0,   1,   2,   3,   4,    5]  minIndexHeap indexs
    MinIndexHeap<Weight> ipq;
    bool *visited;  // record whether the vertex visited    visited[vertex]
    // record the vertex's min edge, for example  0 -> 1  , edgeTo[0] represent edge 0 to 1
    vector<Edge<Weight> *> edgeTo;
    vector<Edge<Weight>> mst;       // minimal spanning tree
    Weight minWeight;

    void handler(int v) {
        // determine whether the point(vertex) has been visited
        assert(!visited[v]);
        visited[v] = true;

        // initialize iterator to iterator points which connected with point v
        typename Graph::adjIterator adj(G, v);
        for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next()) {
            // the edge other vertex not red color
            int other_v = e->other(v);
            if (!visited[other_v]) {
                // save e to edgeTo
                // judge whether the other_v's relate edge has been pushed to edgeTo
                if (!edgeTo[other_v]) {
                    edgeTo[other_v] = e;
                    ipq.insert(other_v, e->wt());

                    // judge whether the pushed edge's weight less than current edge weight e->wt()
                } else if (e->wt() < edgeTo[other_v]->wt()) {
                    edgeTo[other_v] = e;
                    ipq.update(other_v, e->wt());
                }
            }
        }
    }

public:
    PrimMST(Graph &graph) : G(graph), ipq(MinIndexHeap<Weight>(graph.V())) {
        visited = new bool[graph.V()];
        for (int i = 0; i < graph.V(); i++) {
            visited[i] = false;
            edgeTo.push_back(NULL);
        }
        mst.clear();

        // handler PrimMST
        handler(0);
        while (!ipq.isEmpty()) {
            int min_index = ipq.popIndex();
            assert(edgeTo[min_index]);
            mst.push_back(*edgeTo[min_index]);
            handler(min_index);
        }

        cout << "MST: " << endl;
        for (int i = 0; i < mst.size(); i++) {
            cout << mst[i] << endl;
        }
    }
};

#endif //MST_PRIMMST_H
