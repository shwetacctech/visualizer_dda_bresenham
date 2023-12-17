#pragma once
#include "Point3D.h"
class BezierCurve
{
public:
    BezierCurve();
    virtual ~BezierCurve();

    QVector<Point3D> generateCubicBezierCurve(const Point3D& P0, const Point3D& P1, const Point3D& P2, const Point3D& P3, int numberOfPoints);

private:
    Point3D cubicBezierPoint(float t, const Point3D& P0, const Point3D& P1, const Point3D& P2, const Point3D& P3);

};

