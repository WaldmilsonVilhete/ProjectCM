#include "Utils.h"

void Utils::test() {
	cout << "ceva";
}
bool Utils::checkButtonCircle(int x, int y, Point center, float radious)
{
	float xDifferenceSquared, yDifferenceSquared;
	xDifferenceSquared = (float)x - center.x;
	xDifferenceSquared = xDifferenceSquared * xDifferenceSquared;
	yDifferenceSquared = (float)y - center.y;
	yDifferenceSquared = yDifferenceSquared * yDifferenceSquared;
	if (xDifferenceSquared + yDifferenceSquared < radious * radious) {
		return true;
	}
	return false;
}

bool Utils::checkButtonRectangle(int x, int y, Point rightDownCorner, Point leftUpCorner) 
{
	if (x > leftUpCorner.x && x < rightDownCorner.x) {
		if (y > leftUpCorner.y && y < rightDownCorner.y) {
			return true;
		}
	}
	return false;
}
