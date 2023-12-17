#pragma once
#include "Point3D.h"
class BSpline
{
public:
    BSpline(); // Default constructor declaration
    ~BSpline(); // Destructor declaration
    static QVector<Point3D> generateBSpline(const QVector<Point3D>& controlPoints, int degree);

private:
    static double calculateBasis(int i, int degree, double u, const QVector<double>& knots);
    QVector<double> generateKnots(int numControlPoints, int degree);
};
