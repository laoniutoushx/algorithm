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
template<typename Weight>
class LazyPrimMST {
private:
    Graph &G;
    int *visited;
    vector<Edge<Weight>> mst;
    MinIndexHeap<Edge<Weight>> pq;      // priority queue
    Weight mstWeight;
public:
    LazyPrimMST(Graph &graph) : G(graph), pq(MinIndexHeap<Edge<Weight>>(graph.E())) {
        visited = new bool[G.V()];
        // init vertex whether visited
        for (int i = 0; i < G.V(); i++) {
            visited[i] = false;
        }
        mst.clear();
    }
};

#endif //GRAPH_LAZYPRIMMST_H
