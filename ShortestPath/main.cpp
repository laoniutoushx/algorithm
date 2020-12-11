#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include "Edge.h"
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "UnionFind.h"
#include "ReadGraph.h"
#include "MinimumIndexHeap.h"
#include "Dijkstra.h"
#include "Bellman-Ford.h"

using namespace std;

int main() {
//    string filename = "test.txt";
//    int V = 6;

//    SparseGraph<int> g = SparseGraph<int>(V, true);
//    ReadGraph<SparseGraph<int>, int> readGraph(g, filename);
//
//    cout << "Test dijkstra: " << endl;
//    Dijkstra<SparseGraph<int>, int> dij(g, 0);
//    for (int i = 0; i < V; i++) {
//        cout << "shortest path to" << i << " : " << dij.shortestPathTo(i) << endl;
//        dij.showPath(i);
//        cout << "-----------" << endl;
//    }

    string filename2 = "testG2.txt";
    int V2 = 6;

    SparseGraph<int> g = SparseGraph<int>(V2, true);
    ReadGraph<SparseGraph<int>, int> readGraph(g, filename2);

    cout << "Test dijkstra: " << endl;
    Bellman_Ford<SparseGraph<int>, int> bf(g, 0);
    for (int i = 0; i < V2; i++) {
        cout << "shortest path to" << i << " : " << bf.shortestPathTo(i) << endl;
        bf.showPath(i);
        cout << "-----------" << endl;
    }

    return 0;
}
