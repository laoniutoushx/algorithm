//
// Created by SuzumiyaHaruhi on 2020/4/21.
//

#ifndef SHORTESTPATH_BELLMAN_FORD_H
#define SHORTESTPATH_BELLMAN_FORD_H

#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include "Edge.h"
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "UnionFind.h"

// relaxation every point to find the shorest path
template<typename Graph, typename Weight>
class Bellman_Ford {
private:
    Graph &G;
    int s;      // start point
    vector<Edge<Weight> *> from;
    Weight *distTo;
    bool hasNegativeCycle;

    bool checkNegativeCycle() {
        // relaxation
        for (int i = 0; i < G.V(); i++) {
            // to find the shortest path to s, must relaxation every point to get short weight
            typename Graph::adjIterator adj(G, i);  // traversal the points adjacent to s
            for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next()) {
                // if the adjacent point w not have shortest edge or s to w is shortest than ever recorded
                if (!from[e->w()] || distTo[e->v()] + e->wt() < distTo[e->w()]) {
                    // record current the minimal weight to the point w
                    return true;
                }
            }
        }

        return false;
    }

public:
    Bellman_Ford(Graph &graph, int s) : G(graph), s(s) {
        // initialization
        distTo = new Weight[G.V()];
        for (int i = 0; i < G.V(); i++) {
            from.push_back(NULL);
        }

        // start s
        distTo[s] = Weight();
        // to find the point shortest path in a negative power directed graph, every point must traversal v - 1 times
        for (int pass = 0; pass < G.V() - 1; pass++) {
            // relaxation
            for (int i = 0; i < G.V(); i++) {
                // to find the shortest path to s, must relaxation every point to get short weight
                typename Graph::adjIterator adj(G, i);  // traversal the points adjacent to s
                for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next()) {
                    // if the adjacent point w not have shortest edge or s to w is shortest than ever recorded
                    if (!from[e->w()] || distTo[e->v()] + e->wt() < distTo[e->w()]) {
                        // record current the minimal weight to the point w
                        from[e->w()] = e;
                        distTo[e->w()] = distTo[e->v()] + e->wt();
                    }
                }
            }
        }

        hasNegativeCycle = checkNegativeCycle();
    }

    Weight shortestPathTo(int w) {
        assert(!hasNegativeCycle);
        return distTo[w];
    }

    bool hasPathTo(int w) {
        assert(!hasNegativeCycle);
        return from[w] != NULL;
    }

    void shortestPath(int w, vector<Edge<Weight>> &vec) {
        assert(!hasNegativeCycle);

        stack<Edge<Weight> *> s;
        Edge<Weight> *e = from[w];
        while (e != NULL) {
            s.push(e);
            e = from[e->v()];
        }

        while (!s.empty()) {
            e = s.top();
            vec.push_back(*e);
            s.pop();
        }
    }

    void showPath(int w) {
        assert(w >= 0 && w < G.V());
        assert(!hasNegativeCycle);

        vector<Edge<Weight>> vec;
        shortestPath(w, vec);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i].v() << " -> ";
            if (i == vec.size() - 1) {
                cout << vec[i].w() << endl;
            }
        }
    }
};

#endif //SHORTESTPATH_BELLMAN_FORD_H
