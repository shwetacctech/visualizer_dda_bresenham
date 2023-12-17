#include "stdafx.h"
#include "BezierCurve.h"
#include "BezierCurve.h"
#include <vector>

BezierCurve::BezierCurve() {
    // Constructor
}

BezierCurve::~BezierCurve() {
    // Destructor
}

QVector<Point3D> BezierCurve::generateCubicBezierCurve(const Point3D& P0, const Point3D& P1, const Point3D& P2, const Point3D& P3, int numberOfPoints) {
    QVector<Point3D> curvePoints;

    for (int i = 0; i <= numberOfPoints; ++i) {
        float t = static_cast<float>(i) / static_cast<float>(numberOfPoints);
        Point3D point = cubicBezierPoint(t, P0, P1, P2, P3);
        curvePoints<<point;
    }

    return curvePoints;
}

Point3D BezierCurve::cubicBezierPoint(float t, const Point3D& P0, const Point3D& P1, const Point3D& P2, const Point3D& P3) {
    float u = 1.0f - t;
    float tt = t * t;
    float uu = u * u;
    float uuu = uu * u;
    float ttt = tt * t;

    float x = uuu * P0.getX() + 3 * uu * t * P1.getX() + 3 * u * tt * P2.getX() + ttt * P3.getX();
    float y = uuu * P0.getY() + 3 * uu * t * P1.getY() + 3 * u * tt * P2.getY() + ttt * P3.getY();
    float z = uuu * P0.getZ() + 3 * uu * t * P1.getZ() + 3 * u * tt * P2.getZ() + ttt * P3.getZ();

    return Point3D(x, y, z);
}
