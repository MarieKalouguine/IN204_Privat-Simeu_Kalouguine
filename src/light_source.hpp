#ifndef LIGHT_SOURCE_HPP
#define LIGHT_SOURCE_HPP

#include "math_objects.hpp"


/**
 * Any light source (abstract class)
 */
class Light_source
{
public:
	Light_source(double b): brightness(b) {};
	virtual Ray ray_from_point(const Point&) const = 0;		//this method creates a ray from a given point to the light source
	double get_brightness()
	{
		return brightness;
	}
protected:
	double brightness;
};


/**
 * A light source with a stable position
 */
class Lamp : public Light_source
{
public:
	Lamp(const Point& O, double b): Light_source(b), origin(O) {};
	Ray ray_from_point(const Point&) const;
private:
	Point origin;	//position of the lamp
};


/**
 * A light source at infinite position
 */
class Sun : public Light_source		//A light source at infinite position
{
public:
	Sun(const Ray& d, double b): Light_source(b), direction(d) {};
	Ray ray_from_point(const Point&) const;
private:
	Ray direction;	//all the rays from the sun are parallel to this ray
};

#endif
