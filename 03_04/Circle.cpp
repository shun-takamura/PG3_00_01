#include "Circle.h"

void Circle::Size()
{
    size = 3.14f * radius * radius;
}

void Circle::Draw()
{
    printf("%f\n", size);
}