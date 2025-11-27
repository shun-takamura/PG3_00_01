#pragma once
#include "Payment.h"
class CreditCard :public Payment
{
    void Pay() override;
};

