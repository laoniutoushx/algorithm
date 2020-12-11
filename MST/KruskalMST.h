//
// Created by haruhi on 2020/4/11.
//

#ifndef MST_KRUSKALMST_H
#define MST_KRUSKALMST_H

#include <iostream>
#include <cassert>
#include <vector>
#include "Edge.h"
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "MinimumIndexHeap.h"
#include "UnionFind.h"

template<typename Graph, typename Weight>
class KruskalMST {
private:
    vector<Edge<Weight>> mst;
public:
    KruskalMST(Graph &graph) {
        MinIndexHeap<Edge<Weight>> ipq(graph.E());

        // sort all edge by weight
        for (int i = 0; i < graph.V(); i++) {
            typename Graph::adjIterator adj(graph, i);
            for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next()) {
                if (e->w() < e->v()) {
                    ipq.add(*e);
                }
            }
        }

        UnionFind uf(graph.V());

        // every time, chose the least weight edge, add to mst
        // if the vertex on the edge not form a loop(not connected), it must be the edge of mst
        while (!ipq.isEmpty() && mst.size() < graph.V() - 1) {
            // sort and get min edge
            Edge<Weight> minEdge = ipq.pop();

            // judge the two points on edge whether connected before add to mst
            if (!uf.isConnected(minEdge.w(), minEdge.v())) {
                uf.unionElements(minEdge.w(), minEdge.v());
                mst.push_back(minEdge);
            }
        }

        cout << "Kruskal MST: " << endl;
        for (int i = 0; i < mst.size(); i++) {
            cout << mst[i] << endl;
        }
    }


};

#endif //MST_KRUSKALMST_H
