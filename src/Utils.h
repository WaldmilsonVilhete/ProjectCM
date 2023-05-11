#pragma once

#include "ofMain.h"
#include "Point.h"

class Utils
{
public:
	void test();
	bool checkButtonCircle(int x, int y, Point center, float radious);
	bool checkButtonRectangle(int x, int y, Point rightDownCorner, Point leftUpCorner);
};

