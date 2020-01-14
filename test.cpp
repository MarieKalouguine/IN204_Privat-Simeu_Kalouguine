#include <iostream>
#include "objects.hpp"

int main()
{
	Ray r(Point(0.5, 0, -1), Point(0.5, 0, 1));
	Sphere S(Point(0,0,0), 1, 0);
	S.compute_intersect(r);
}
