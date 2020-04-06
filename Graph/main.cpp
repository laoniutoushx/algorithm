#include <iostream>
#include <ctime>
#include <string>
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "ReadGraph.h"
#include "Component.h"

int main() {
//    int N = 20;
//    int M = 100;
//    bool directed = true;
//
//    srand(time(NULL));
//
//    // SparseGraph
//    SparseGraph g1(N, directed);
//    for (int i = 0; i < M; i++) {
//        int a = rand() % N;
//        int b = rand() % N;
//        g1.addEdge(a, b);
//    }
//
//    for (int v = 0; v < N; v++) {
//        cout << v << " : ";
//        SparseGraph::adjIterator adj(g1, v);
//        for (int w = adj.begin(); !adj.end(); w = adj.next())
//            cout << w << " ";
//        cout << endl;
//    }

    string filename01 = "graph01.txt";
    string filename02 = "graph02.txt";

    SparseGraph g1(13, false);
    ReadGraph<SparseGraph> readGraph1(g1, filename02);
    Component<SparseGraph> component1(g1);
    g1.showInfo(g1);



    DenseGraph g2(6, false);
    ReadGraph<DenseGraph> readGraph2(g2, filename01);
    Component<DenseGraph> component2(g2);
    g2.showInfo(g2);

    cout << filename02 << " component count:" << component1.component() << endl;
    cout << filename01 << " component count:" << component2.component() << endl;

    cout << "7 & 12 is connected:" << component1.isConnected(7, 12) << endl;
    return 0;
}
