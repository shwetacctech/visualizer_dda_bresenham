#include "stdafx.h"
#include "HermiteCurve.h"
#include "HermiteCurve.h"
#include "Point3D.h" 

HermiteCurve::HermiteCurve() {
    
}

HermiteCurve::~HermiteCurve() {
    
}

QVector<Point3D> HermiteCurve::generateHermiteCurve(const Point3D& P0, const Point3D& P1, const Point3D& T0, const Point3D& T1, int numberOfPoints) {
    QVector<Point3D> curvePoints;

    for (int i = 0; i <= numberOfPoints; ++i) {
        float t = static_cast<float>(i) / static_cast<float>(numberOfPoints);
        Point3D point = evaluateHermiteCurve(t, P0, P1, T0, T1);
        curvePoints << point;
    }

    return curvePoints;
}

Point3D HermiteCurve::evaluateHermiteCurve(float t, const Point3D& P0, const Point3D& P1, const Point3D& T0, const Point3D& T1) {
    float t2 = t * t;
    float t3 = t2 * t;
    float two_t3 = 2 * t3;
    float three_t2 = 3 * t2;

    float h1 = two_t3 - three_t2 + 1;
    float h2 = -two_t3 + three_t2;
    float h3 = t3 - 2 * t2 + t;
    float h4 = t3 - t2;

    float x = h1 * P0.getX() + h2 * P1.getX() + h3 * T0.getX() + h4 * T1.getX();
    float y = h1 * P0.getY() + h2 * P1.getY() + h3 * T0.getY() + h4 * T1.getY();
    float z = h1 * P0.getZ() + h2 * P1.getZ() + h3 * T0.getZ() + h4 * T1.getZ();

    return Point3D(x, y, z);
}
