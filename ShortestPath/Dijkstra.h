//
// Created by SuzumiyaHaruhi on 2020/4/15.
//

#ifndef SHORTESTPATH_DIJKSTRA_H
#define SHORTESTPATH_DIJKSTRA_H

#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include "Edge.h"
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "UnionFind.h"
#include "MinimumIndexHeap.h"

// single source shortest path
template<typename Graph, typename Weight>
class Dijkstra {
private:
    int s;           // start point
    Graph &G;           // graph
    bool *visited;      // record the point whether visited
    Weight *distTo;          // the weight of s to every point (include self)
    // the shortest path to s, everytime traversal all the connected point with current shorest point
    vector<Edge<Weight> *> from;

public:
    Dijkstra(Graph &graph, int s) : G(graph) {
        this->s = s;
        visited = new bool[graph.V()];
        distTo = new Weight[graph.V()];
        MinIndexHeap<Weight> ipq(graph.V());
        for (int i = 0; i < graph.V(); i++) {
            visited[i] = false;
            distTo[i] = Weight();
            from.push_back(NULL);
        }

        // start
        visited[s] = true;
        distTo[s] = Weight();
        ipq.insert(s, distTo[s]);

        while (!ipq.isEmpty()) {
            int v = ipq.popIndex();
            visited[v] = true;

            // Relaxation
            typename Graph::adjIterator adj(graph, v);
            for (Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next()) {
                int w = e->other(v);
                if (!visited[w]) {
                    if (from[w] == NULL || distTo[v] + e->wt() < distTo[w]) {
                        distTo[w] = distTo[v] + e->wt();
                        from[w] = e;
                        if (ipq.containIndex(w)) {
                            ipq.update(w, distTo[w]);
                        } else {
                            ipq.insert(w, distTo[w]);
                        }
                    }
                }
            }
        }
    }

    ~Dijkstra() {
        delete[] visited;
        delete[] distTo;
    }

    Weight shortestPathTo(int w) {
        return distTo[w];
    }

    bool hasPathTo(int w) {
        return visited[w];
    }

    void shortestPath(int w, vector<Edge<Weight>> &vec) {
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

#endif //SHORTESTPATH_DIJKSTRA_H
