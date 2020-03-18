#include <iostream>
#include <algorithm>
#include "BinaryHeap.h"

using namespace std;


int main(){
    MaxHeap<int> maxheap = MaxHeap<int>(100);

    srand(time(NULL));

    for(int i = 0; i < 24; i++){
        maxheap.insert(rand() % 90 + 10);
    }       

    maxheap.printBinaryHeap();

    cout << endl;
    cout << "size:" << maxheap.size() << endl;

    for(int i = 15; i > 0; i--){
        cout << maxheap.extractMax() << endl;
        maxheap.printBinaryHeap();
    }

    return 0;
}
