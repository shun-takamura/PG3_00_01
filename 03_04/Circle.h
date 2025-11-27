#pragma once
#include "IShape.h"
class Circle :public IShape{
private:
    float radius;
    float size = 0.0f;

public:
    Circle(float r) {
        radius = r;
    }

    void Size() override;
    void Draw() override;
};

