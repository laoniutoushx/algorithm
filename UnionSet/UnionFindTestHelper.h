//
// Created by haruhi on 2020/3/29.
//

#ifndef UNIONSET_I_UNIONFINDTESTHELPER_H
#define UNIONSET_I_UNIONFINDTESTHELPER_H

#include <iostream>
#include <ctime>
#include "UnionFindI.h"
#include "UnionFindII.h"
#include "UnionFindIII.h"
#include "UnionFindIV.h"
#include "UnionFindV.h"

// 为每个节点添加 子节点数量 属性， 平衡树高度
using namespace std;
namespace UnionFindTestHelper {
    void testUFI(int n){
        srand(time(NULL));
        UFI::UnionFind uf = UFI::UnionFind(n);

        time_t startTime = clock();

        for(int i = 0; i < n; i++){
            int a = rand() % n;
            int b = rand() % n;
            uf.unionE(a, b);
        }

        for(int i = 0; i < n; i++){
            int a = rand() % n;
            int b = rand() % n;
            uf.isConnected(a, b);
        }

        time_t endTime = clock();

        cout << "UFI, " << 2 * n << " ops, " << double (endTime - startTime) / CLOCKS_PER_SEC << endl;
    }

    void testUFII(int n){
        srand(time(NULL));
        UFII::UnionFind uf = UFII::UnionFind(n);

        time_t startTime = clock();

        for(int i = 0; i < n; i++){
            int a = rand() % n;
            int b = rand() % n;
            uf.unionE(a, b);
        }

        for(int i = 0; i < n; i++){
            int a = rand() % n;
            int b = rand() % n;
            uf.isConnected(a, b);
        }

        time_t endTime = clock();

        cout << "UFII, " << 2 * n << " ops, " << double (endTime - startTime) / CLOCKS_PER_SEC << endl;
    }

    void testUFIII(int n){
        srand(time(NULL));
        UFIII::UnionFind uf = UFIII::UnionFind(n);

        time_t startTime = clock();

        for(int i = 0; i < n; i++){
            int a = rand() % n;
            int b = rand() % n;
            uf.unionE(a, b);
        }

        for(int i = 0; i < n; i++){
            int a = rand() % n;
            int b = rand() % n;
            uf.isConnected(a, b);
        }

        time_t endTime = clock();

        cout << "UFIII, " << 2 * n << " ops, " << double (endTime - startTime) / CLOCKS_PER_SEC << endl;
    }

    void testUFIV(int n){
        srand(time(NULL));
        UFIV::UnionFind uf = UFIV::UnionFind(n);

        time_t startTime = clock();

        for(int i = 0; i < n; i++){
            int a = rand() % n;
            int b = rand() % n;
            uf.unionE(a, b);
        }

        for(int i = 0; i < n; i++){
            int a = rand() % n;
            int b = rand() % n;
            uf.isConnected(a, b);
        }

        time_t endTime = clock();

        cout << "UFIV, " << 2 * n << " ops, " << double (endTime - startTime) / CLOCKS_PER_SEC << endl;
    }

    void testUFV(int n){
        srand(time(NULL));
        UFV::UnionFind uf = UFV::UnionFind(n);

        time_t startTime = clock();

        for(int i = 0; i < n; i++){
            int a = rand() % n;
            int b = rand() % n;
            uf.unionE(a, b);
        }

        for(int i = 0; i < n; i++){
            int a = rand() % n;
            int b = rand() % n;
            uf.isConnected(a, b);
        }

        time_t endTime = clock();

        cout << "UFV, " << 2 * n << " ops, " << double (endTime - startTime) / CLOCKS_PER_SEC << endl;
    }
}

#endif //UNIONSET_I_UNIONFINDTESTHELPER_H
