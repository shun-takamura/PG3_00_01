#include"Payment.h"
#include"Cash.h"
#include"CreditCard.h"
#include "QRPayment.h"

int main(){
    
    Payment* p1 = new Cash();
    Payment* p2 = new CreditCard();
    Payment* p3 = new QRPayment();

    // ポリモーフィズム
    p1->Pay();
    p2->Pay();
    p3->Pay();

    delete p1;
    delete p2;
    delete p3;

    return 0;
}