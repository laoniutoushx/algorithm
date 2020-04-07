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

    Weight wt() { return w; }

    int other(int x) {
        assert(x == a || x == b);
        return x == a ? b : a;
    }

    friend ostream &operator<<(ostream &os, const Edge &e) {
        os << e.a << "-" << e.b << ": " << e.weight;
        return os;
    }

    bool operator<(Edge<Weight> &e) { return weight < e.wt(); }

    bool operator<=(Edge<Weight> &e) { return weight <= e.wt(); }

    bool operator>(Edge<Weight> &e) { return weight > e.wt(); }

    bool operator>=(Edge<Weight> &e) { return weight >= e.wt(); }

    bool operator==(Edge<Weight> &e) { return weight == e.wt(); }

};

#endif //GRAPH_EDGE_H
