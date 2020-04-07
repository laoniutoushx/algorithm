#include <iostream>
#include "ReadGraph.h"
#include "DenseGraph.h"
#include "SparseGraph.h"

int main() {
    string filename = "test.txt";
    DenseGraph<double> denseGraph1(8, true);
    ReadGraph<DenseGraph<double>, double> readGraph1(denseGraph1, filename);
    denseGraph1.showInfo();

    SparseGraph<double> sparseGraph(8, true);
    ReadGraph<SparseGraph<double>, double> readGraph2(sparseGraph, filename);
    sparseGraph.showInfo(sparseGraph);

    return 0;
}
