#include "stdafx.h"
#include "BSpline.h"
#include <cmath> 
BSpline::BSpline() {
}
BSpline::~BSpline() {
}
QVector<double> BSpline:: generateKnots(int numControlPoints, int degree) {
    int m = numControlPoints + degree + 1;
    QVector<double> knots(m + 1);

    // Set the first p+1 knots to 0
    for (int i = 0; i <= degree; ++i) {
        knots[i] = 0.0;
    }

    // Calculate and set the internal knots
    for (int i = degree + 1; i <= numControlPoints; ++i) {
        knots[i] = static_cast<double>(i - degree) / static_cast<double>(numControlPoints - degree);
    }

    // Set the last p+1 knots to 1
    for (int i = numControlPoints + 1; i <= m; ++i) {
        knots[i] = 1.0;
    }

    return knots;
}
QVector<Point3D> BSpline::generateBSpline(const QVector<Point3D>& controlPoints, int degree) {
    int n = controlPoints.size() - 1; // Number of control points
    int m = n + degree + 1; // Total number of knots
    QVector<double> knots;
    knots= generateKnots(n, degree);
    // Calculate knots (you need to have appropriate knot vector as per B-spline rules)
    
    QVector<Point3D> result; // Vector to store the B-spline curve points

    // Iterate over u parameter values
    for (double u = knots[degree]; u <= knots[m - degree]; u += 0.01) {
        Point3D point; // Initialize the point on the B-spline curve

        // Calculate the point on the B-spline curve at parameter u
        for (int i = 0; i <= n; ++i) {
            double basis = calculateBasis(i, degree, u, knots); // Calculate the basis function value
            point.setX(point.getX() + controlPoints[i].getX() * basis);
            point.setY(point.getY() + controlPoints[i].getY() * basis);
            point.setZ(point.getZ() + controlPoints[i].getZ() * basis);
            result.push_back(point); // Add the point to the result vector
        }
    }
    return result;
}
double BSpline::calculateBasis(int i, int degree, double u, const QVector<double>& knots) {
    if (degree == 0) {
        // Base case: If degree is 0, the basis function is 1 if the parameter is within the knot span (u_i <= u < u_i+1), else 0.
        if (u >= knots[i] && u < knots[i + 1]) {
            return 1.0;
        }
        else {
            return 0.0;
        }
    }
    else {
        double basis = 0.0;

        // Calculate the recursive basis function using Cox-de Boor formula
        double denom1 = knots[i + degree] - knots[i];
        double denom2 = knots[i + degree + 1] - knots[i + 1];

        if (denom1 != 0) {
            basis += ((u - knots[i]) / denom1) * calculateBasis(i, degree - 1, u, knots);
        }

        if (denom2 != 0) {
            basis += ((knots[i + degree + 1] - u) / denom2) * calculateBasis(i + 1, degree - 1, u, knots);
        }

        return basis;
    }
}
