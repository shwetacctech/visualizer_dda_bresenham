#include "pch.h"
#include "Line.h"

Line::Line(Point3D p1, Point3D p2) : mP1(p1), mP2(p2)
{
}
Line::~Line() {}

Point3D Line::getP1()
{
	return mP1;
}

Point3D Line::getP2()
{
	return mP2;
}

void Line::setP1(Point3D p)
{
	mP1 = p;
}

void Line::setP2(Point3D p)
{
	mP2 = p;
}