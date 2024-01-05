#ifndef _MY_UTILS_
#define _MY_UTILS_ 1

#include "ListNode.h"

template<typename T>
void print(vector<T> v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

#endif
