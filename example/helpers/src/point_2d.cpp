#include "point_2d.h"

double distance(Point2D a, Point2D b)
{
	return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

Point2D center(std::vector<Point2D> points)
{
	Point2D c;
	for (auto p : points)
	{
		c.x += p.x;
		c.y += p.y;
	}
	c.x /= points.size();
	c.y /= points.size();
	return c;
}