//
// Created by haruhi on 2020/4/6.
//

#ifndef GRAPH_PATH_H
#define GRAPH_PATH_H

#include <iostream>
#include <cassert>
#include <stack>
#include <vector>

using namespace std;

template<typename Graph>
class Path {
private:
    Graph &G;
    int s;      // start vertex, means from s to ?
    bool *visited;
    int *from;  // from[index] = value,  index is current vertex, value is pre vertex

    void dfs(int v) {

        assert(v >= 0 && v < G.V());

        visited[v] = true;      // mark the visited vertex
        typename Graph::adjIterator adj(G, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if (!visited[i]) {
                from[i] = v;    // record the per vertex
                dfs(i);         // deep first search
            }
        }
    }

public:
    /**
     * @param s     source  origin vertex
     */
    Path(Graph &graph, int s) : G(graph) {
        assert(s >= 0 && s < graph.V());

        visited = new bool[graph.V()];
        from = new int[graph.V()];
        for (int i = 0; i < graph.V(); i++) {
            visited[i] = false;
            from[i] = -1;
        }
        this->s = s;

        // path search
        dfs(s);
    }

    ~Path() {
        delete[] visited;
        delete[] from;
    }

    bool hasPath(int w) {
        assert(w >= 0 && w < G.V());
        return visited[w];
    }

    void path(int w, vector<int> &vec) {
        assert(w >= 0 && w < G.V());

        stack<int> ss;

        int p = w;
        while (p != -1) {
            ss.push(p);
            p = from[p];
        }

        vec.clear();
        while (!ss.empty()) {
            vec.push_back(ss.top());
            ss.pop();
        }
    }

    void showPath(int w) {
        vector<int> vec;
        path(w, vec);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i];
            if (i == vec.size() - 1) {
                cout << endl;
            } else {
                cout << " -> ";
            }
        }
    }
};

#endif //GRAPH_PATH_H
