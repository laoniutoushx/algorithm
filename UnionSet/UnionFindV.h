//
// Created by haruhi on 2020/3/29.
//

#ifndef UNIONSET_V_UNIONFINDII_H
#define UNIONSET_V_UNIONFINDII_H

#include <iostream>
#include <assert.h>

// Path Compression
using namespace std;
namespace UFV {
    /*
     * 每个节点都有一个指针指向父节点，根节点指向自己
     * [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]   index
     * [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]   父节点 index
     * [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]   每个节点下孩子数
     */
    class UnionFind {
    private:
        int *parent;
        int *size;
        int count;
    public:
        UnionFind(int n) {
            this->count = n;
            this->size = new int[n];
            this->parent = new int[n];
            for (int i = 0; i < n; i++) {
                this->parent[i] = i;
                this->size[i] = 1;
            }
        }

        ~UnionFind() {
            delete[] this->parent;
        }

        // 获取根节点
        int find(int index) {
            assert(index >= 0 && index < this->count);
            // path compression
//            while (index != this->parent[index]){
//                this->parent[index] = this->parent[parent[index]];
//                index = this->parent[index];
//            }
//            return this->parent[index];

            if (index != this->parent[index]){
                this->parent[index] = this->find(this->parent[index]);
            }
            return parent[index];
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
            if (this->size[pRoot] < this->size[qRoot]) {
                this->parent[pRoot] = qRoot;
            }else if(this->size[qRoot] < this->size[pRoot]){
                this->parent[qRoot] = pRoot;
            }else{
                this->parent[qRoot] = pRoot;
                this->size[pRoot] += this->size[qRoot];
            }
        }
    };
}


#endif //UNIONSET_V_UNIONFINDII_H
