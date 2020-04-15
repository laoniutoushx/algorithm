//
// Created by SuzumiyaHaruhi on 2020/4/15.
//

#ifndef SHORTESTPATH_DIJKSTRA_H
#define SHORTESTPATH_DIJKSTRA_H

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "UnionFind.h"
#include "MinimumIndexHeap.h"

template <typename Graph, typename Weight>
class Dijkstra {
private:
    Graph &G;
    bool *visited;
    vector<Edge<Weight>> edgeTo;
    MinIndexHeap<Edge<Weight>> ipq;
public:

};

#endif //SHORTESTPATH_DIJKSTRA_H
