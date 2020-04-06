//
// Created by haruhi on 2020/4/6.
//

#ifndef GRAPH_SHORTESTPATH_H
#define GRAPH_SHORTESTPATH_H

#include <iostream>
#include <cassert>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

// this class can be use to calculate shortest path in unweighted graph
template<typename Graph>
class ShortestPath {
private:
    Graph &G;
    int s;      // start vertex, means from s to v
    bool *visited;
    int *from;  // from[index] = value,  index is current vertex, value is pre vertex
    int *ord;   // the distance between current vertex {v} and source vertex {s}

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

    void bfs(int rVertex) {
        assert(rVertex >= 0 && rVertex < G.V());

        visited[rVertex] = true;
        ord[rVertex] = 0;

        queue<int> prepareToIter;
        prepareToIter.push(rVertex);

        while(!prepareToIter.empty()){
            int v = prepareToIter.front();
            prepareToIter.pop();
            typename Graph::adjIterator adj(G, v);      // iterator vertex v
            for(int i = adj.begin(); !adj.end(); i = adj.next()){
                if(!visited[i]){
                    from[i] = v;            // record the pre vertex
                    visited[i] = true;      // whether visited
                    ord[i] = ord[v] + 1;    // calculate distance
                    prepareToIter.push(i);
                }
            }
        }

    }

public:
    /**
     * @param s     source  origin vertex
     */
    ShortestPath(Graph &graph, int s) : G(graph) {
        assert(s >= 0 && s < graph.V());

        visited = new bool[graph.V()];
        from = new int[graph.V()];
        ord = new int[graph.V()];
        for (int i = 0; i < graph.V(); i++) {
            visited[i] = false;
            from[i] = -1;
            ord[i] = -1;
        }
        this->s = s;

        // shortest path search by bfs(breadth-first search)
        bfs(s);
    }

    ~ShortestPath() {
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

    // return the distance between source vertex {s} and target/current vertex {v}
    int length(int w){
        assert(w >= 0 && w < G.V());
        return ord[w];
    }
};

#endif //GRAPH_SHORTESTPATH_H
