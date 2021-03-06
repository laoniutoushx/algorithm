//
// Created by haruhi on 2020/3/29.
//

#ifndef UNIONSET_IV_UNIONFINDII_H
#define UNIONSET_IV_UNIONFINDII_H

#include <iostream>
#include <assert.h>

// QuickUnion
using namespace std;
namespace UFIV {
    /*
     * 每个节点都有一个指针指向父节点，根节点指向自己
     * [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]   index
     * [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]   父节点 index
     * [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]   每个节点高度
     */
    class UnionFind {
    private:
        int *parent;
        int *rank;
        int count;
    public:
        UnionFind(int n) {
            this->count = n;
            this->rank = new int[n];
            this->parent = new int[n];
            for (int i = 0; i < n; i++) {
                this->parent[i] = i;
                this->rank[i] = 1;
            }
        }

        ~UnionFind() {
            delete[] this->parent;
        }

        // 获取根节点
        int find(int index) {
            assert(index >= 0 && index < this->count);
            while (index != this->parent[index])
                index = this->parent[index];
        }

        // 判断两个节点的根节点是否相等
        bool isConnected(int p, int q) {
            int pRoot = this->find(p);
            int qRoot = this->find(q);
            return pRoot == qRoot;
        }

        // 讲一个节点的根节点挂载到另一个节点根节点下
        void unionE(int p, int q) {
            int pRoot = this->find(p);
            int qRoot = this->find(q);
            if (pRoot == qRoot)
                return;
            if (this->rank[pRoot] < this->rank[qRoot]) {
                this->parent[pRoot] = qRoot;
            }else if(this->rank[qRoot] < this->rank[pRoot]){
                this->parent[qRoot] = pRoot;
            }else{
                this->parent[qRoot] = pRoot;
                this->rank[pRoot]++;
            }
        }
    };
}


#endif //UNIONSET_IV_UNIONFINDII_H
