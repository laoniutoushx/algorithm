#include <iostream>
#include "DenseGraph.h"
#include "SparseGraph.h"

int main() {
    int n = 10;
    bool directed = true;
    DenseGraph denseGraph = DenseGraph(n, directed);

    denseGraph.addEdge(0, 1);
    denseGraph.addEdge(1, 2);
    denseGraph.addEdge(2, 3);
    denseGraph.addEdge(2, 4);
    denseGraph.addEdge(3, 4);

    denseGraph.DFS(0);

    cout << "--------" << endl;

    SparseGraph sparseGraph = SparseGraph(n, directed);

    sparseGraph.addEdge(0, 1);
    sparseGraph.addEdge(1, 2);
    sparseGraph.addEdge(2, 3);
    sparseGraph.addEdge(2, 4);
    sparseGraph.addEdge(3, 4);

    sparseGraph.DFS(0);

    return 0;
}
