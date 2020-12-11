#include <iostream>
#include <vector>
#include <string>
#include "SortTestHelper.h"

using namespace std;

int main()
{
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);

    SortTestHelper::printArray(arr, n);
    delete[] arr;
    return 0;
}