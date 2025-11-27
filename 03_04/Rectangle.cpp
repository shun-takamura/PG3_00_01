#include "Rectangle.h"

void Rectangle::Size()
{
    size = width * height;
}

void Rectangle::Draw()
{
	printf("%f\n", size);
}
