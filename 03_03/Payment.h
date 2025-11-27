#pragma once
#include <iostream>
using namespace std;

class Payment{
public:
    virtual void Pay() = 0;
    virtual ~Payment() = default;
};

