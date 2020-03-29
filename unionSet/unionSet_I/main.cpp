#include <iostream>
#include <assert.h>
#include "UnionFind.h"

using namespace std;
using namespace UFI;

int main() {
    int n = 10;
    UFI::UnionFind unionFind = UFI::UnionFind(n);
    for(int i = 0; i < n - 1; i++){
        cout << "is connected:" << unionFind.isConnected(i, i+1) << endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
