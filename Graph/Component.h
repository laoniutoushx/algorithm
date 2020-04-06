//
// Created by SuzumiyaHaruhi on 2020/4/3.
//

#ifndef GRAPH_COMPONENT_H
#define GRAPH_COMPONENT_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;

template<typename Graph>
class Component {
private:
    Graph &G;
    bool *visited;      // a vertex whether visited
    int c_count;         // connected component count in a graph
    int *identify;      // marked different connected component by id, the vertex in same connected component have same identify

    void dfs(int v) {
        assert(v >= 0 && v < G.V());

        visited[v] = true;      // mark the visited vertex
        identify[v] = c_count;   // assign same identify to the vertex in same connected component

        typename Graph::adjIterator adj(G, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if (!visited[i])
                dfs(i);         // deep first search
        }
    }

public:
    Component(Graph &graph) : G(graph) {
        visited = new bool[graph.V()];
        identify = new int[graph.V()];
        c_count = 0;
        for (int i = 0; i < graph.V(); i++) {
            visited[i] = false;
            identify[i] = -1;
        }
        for (int i = 0; i < graph.V(); i++) {
            if (!visited[i]) {
                dfs(i);
                c_count++;
            }
        }
    }

    // Connected Component
    int component() {
        return c_count;
    }

    // isConnected
    bool isConnected(int v, int w) {
        assert(v >= 0 && v < G.V());
        assert(w >= 0 && w < G.V());
        return identify[v] == identify[w];
    }
};

#endif //GRAPH_COMPONENT_H
