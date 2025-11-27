#pragma once
#include "Payment.h"
class QRPayment : public Payment{
public:
    void Pay() override;
};

