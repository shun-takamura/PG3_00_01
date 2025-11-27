#pragma once
#include "Payment.h"
class Cash :public Payment{
public:
    void Pay() override;
};

