//
// Created by haruhi on 2020/3/29.
//

#ifndef UNIONSET_I_UNIONFIND_H
#define UNIONSET_I_UNIONFIND_H

#include <iostream>
#include <assert.h>

using namespace std;
namespace UFI {
    class UnionFind {
    private:
        // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]  此行代表数组 index
        // [1, 1, 2, 2, 3, 3, 4, 5, 7, 1]  相同的值代表 此处（index）是相互连接的
        int *id;    // 表示并查集的数组
        int count;  // 元素数量
    public:
        UnionFind(int n) {
            this->count = n;
            this->id = new int[n];

            // 默认初始化复制，各个节点都不连通
            for (int i = 0; i < n; i++) {
                this->id[i] = i;
            }
        }

        ~UnionFind() {
            delete this->id;
        }

        // 获取连接点的值
        int find(int index) {
            assert(index >= 0 && index < this->count);
            return this->id[index];
        }

        // 判断是否连接
        bool isConnected(int p, int q) {
            if (p == q) return true;
            assert(p >= 0 && p < this->count && q >= 0 && q < this->count);
            return this->id[p] == this->id[q];
        }

        /**
         * 连接两个节点
         * 讲其中一个节点的值全部赋值为另一个节点的值，即为连接
         * @param p p节点
         * @param q q节点
         */
        void unionE(int p, int q) {
            if (p == q) return;
            for (int i = 0; i < this->count; i++)
                if (this->find(p) != this->find((q)))
                    this->id[p] = this->id[q];
        }
    };

}
#endif //UNIONSET_I_UNIONFIND_H
