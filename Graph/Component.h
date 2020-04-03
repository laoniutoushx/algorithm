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
template <typename Graph>
class Component {

public:
    // Connected Component
    int component(Graph &graph){
        int c_count = 0;    // connected component count
        for(int i = 0; i < graph.V(); i++){
            graph.DFS(i);
            c_count++;
        }
        return c_count;
    }

    // isConnected
    bool isConnected(int v, int w){

    }
};

#endif //GRAPH_COMPONENT_H
