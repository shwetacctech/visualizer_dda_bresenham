#pragma once
#include "Point3D.h"
#include "pch.h"
#include <vector>


class BEZIERCURVE_API BezierCurve
{
public:
	BezierCurve(Point3D inP0, Point3D inP1, Point3D inP2, Point3D inP3);
	~BezierCurve();

	void drawCurve(Point3D inP0, Point3D inP1, Point3D inP2, Point3D inP3, std::vector<float>& mVertices, std::vector<float>& mColors);

private:
	Point3D mP0;
	Point3D mP1;
	Point3D mP2;
	Point3D mP3;
};

