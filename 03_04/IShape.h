#pragma once
#include <iostream>
using namespace std;
class IShape
{
public:
	virtual void Size() = 0;
	virtual void Draw() = 0;
	virtual ~IShape() = default;
};

