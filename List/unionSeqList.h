#ifndef UNIONSEQLIST_H
#define UNIONSEQLIST_H

#include <iostream>
#include <ctime>
#include <string>
#include <cassert>

using namespace std;

namespace UnionSeqList
{
    template <typename T>
    T *unionTowOrderedList(T first[], int m, T second[], int n)
    {
        T *unioned = new T[m + n];

        int first_index = 0, second_index = 0;

        while (first_index < m && second_index < n)
        {
            T first_element = first[first_index];
            T second_element = second[second_index];

            if (first_element < second_element)
            {
                unioned[first_index + second_index] = first_element;
                first_index++;
            }
            else
            {
                unioned[first_index + second_index] = second_element;
                second_index++;
            }
        }

        for (; first_index < m; first_index++)
            unioned[first_index + second_index] = first[first_index];

        for (; second_index < n; second_index++)
            unioned[first_index + second_index] = second[second_index];

        return unioned;
    }

    template <typename T>
    void printArray(T arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

} // namespace UnionSeqList

#endif