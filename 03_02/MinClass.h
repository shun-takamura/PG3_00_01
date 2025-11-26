#pragma once
#include <iostream>
using namespace std;

template <typename T1, typename T2>

class MinClass{
public:
    T1 a;
    T2 b;

    MinClass(T1 a, T2 b) : a(a), b(b) {}

    // 小さい方の値を返す
    auto Min() {
        return (a < b) ? a : b;
    }
};

