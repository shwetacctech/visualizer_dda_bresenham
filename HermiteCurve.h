#pragma once
#include <QVector>
#include "Point3D.h" // Assuming Point3D class definition

class HermiteCurve {
public:
    HermiteCurve();
    ~HermiteCurve();

    QVector<Point3D> generateHermiteCurve(const Point3D& P0, const Point3D& P1, const Point3D& T0, const Point3D& T1, int numberOfPoints);
    Point3D evaluateHermiteCurve(float t, const Point3D& P0, const Point3D& P1, const Point3D& T0, const Point3D& T1);

private:
    // Private member variables or helper methods can be added here
};

