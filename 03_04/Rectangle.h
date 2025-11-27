#pragma once
#include "IShape.h"
class Rectangle : public IShape
{
private:
    float width;
    float height;
    float size = 0.0f;

public:

    Rectangle(float w, float h){
        width = w;
        height = h;
    }

    void Size() override;

    void Draw() override;
};

