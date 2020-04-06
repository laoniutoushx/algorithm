//
// Created by haruhi on 2020/4/6.
//

#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

#include <iostream>
#include <cassert>

using namespace std;

// indicate an edge entity
template<typename Weight>
class Edge {
private:
    int a, b;
    Weight weight;
public:
    Edge(int a, int b, Weight weight) {
        this->a = a;
        this->b = b;
        this->w = weight;
    }

    Edge() {};

    ~Edge() {}

    int v() { return a; }

    int w() { return b; }

    int other(int x) {
        assert(x == a || x == b);
        return x == a ? b : a;
    }
};

#endif //GRAPH_EDGE_H
