#pragma once
#include "Point3D.h"
#include "pch.h"


class GEOMETRY_API Line
{
public:
	Line(Point3D p1, Point3D p2);
	~Line();

public:
	Point3D getP1();
	Point3D getP2();
	void setP1(Point3D);
	void setP2(Point3D);
private:
	Point3D mP1;
	Point3D mP2;
};