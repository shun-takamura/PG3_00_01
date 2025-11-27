#include "Circle.h"
#include "Rectangle.h"

int main() {
    IShape* s1 = new Circle(5.0f);
    IShape* s2 = new Rectangle(4.0f, 3.0f);

    s1->Size();
    s2->Size();

    s1->Draw();
    s2->Draw();

    // 後片付け
    delete s1;
    delete s2;

    return 0;
}