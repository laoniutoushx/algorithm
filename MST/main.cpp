#include <iostream>
#include "ReadGraph.h"
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "LazyPrimMST.h"

int main() {
    string filename = "test.txt";
    DenseGraph<double> denseGraph1(8, true);
    ReadGraph<DenseGraph<double>, double> readGraph1(denseGraph1, filename);
    denseGraph1.showInfo();

    SparseGraph<double> sparseGraph(8, false);
    ReadGraph<SparseGraph<double>, double> readGraph2(sparseGraph, filename);
    sparseGraph.showInfo(sparseGraph);

    LazyPrimMST<SparseGraph<double>, double> mst = LazyPrimMST<SparseGraph<double>, double>(sparseGraph);

    return 0;
}
