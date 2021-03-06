#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "math_objects.hpp"

/**
 * A  camera is defined by its origin and the position of the plane where the image is projected.
 * We assume that the bottom of the image is always horizontal.
 */
class Camera
{
public:
	Camera(const Point& O, const Point& T, double w, double h, unsigned wpx, unsigned hpx): origin(O), target(T), width(w), height(h), pxwidth(wpx), pxheight(hpx) {};
	Camera(const Point& O, const Point& T, double w, unsigned wpx, unsigned hpx): origin(O), target(T), width(w), height(hpx*w/wpx), pxwidth(wpx), pxheight(hpx) {};
	Camera(): origin(Point(1,1,1)), target(Point(4,4,4)), width(16), height(12) , pxwidth(400), pxheight(300) {};
	
	Point get_origin() const
	{
		return origin;
	}
	Point get_target() const
	{
		return target;
	}
	double get_width() const
	{
		return width;
	}
	double get_height() const
	{
		return height;
	}
	unsigned get_pxwidth() const
	{
		return pxwidth;
	}
	unsigned get_pxheight() const
	{
		return pxheight;
	}
	
	Ray ray_from_pixel(unsigned x, unsigned y) const;
	
private:
	Point origin, target;	//origin of the camera, and center of the projection plane
	double width, height;	//width and height of the rendered image
	unsigned pxwidth, pxheight;	//width and height of the rendered image
};

#endif
