#include <iostream>
#include <algorithm>

#include "unionSeqList.h"

using namespace std;

int main()
{
    int m = 10, n = 10;
    int first[m], second[n];
    for (int i = 0; i < m; i++)
    {
        if (i % 2 == 0)
            first[i] = i + 1;
        else
            first[i] = i;
    }
    UnionSeqList::printArray(first, m);

    for (int i = 0; i < n; i++)
    {
        if (i % 3 == 0)
            second[i] = i + 3;
        else
            second[i] = i + 2;
    }
    UnionSeqList::printArray(second, n);

    int *unionedList = UnionSeqList::unionTowOrderedList(first, m, second, n);
    UnionSeqList::printArray(unionedList, m + n);
    
    return 0;
}