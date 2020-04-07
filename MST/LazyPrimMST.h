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

using namespace std;

//  minimal spanning tree
template<typename Weight>
class LazyPrimMST {
private:
    Graph &G;
    int *visited;
    Edge<Weight> *visitedEdge;
};

#endif //GRAPH_LAZYPRIMMST_H
