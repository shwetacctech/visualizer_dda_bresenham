#include "pch.h"
#include "BezierCurve.h"

#include <cmath>

BezierCurve::BezierCurve(Point3D inP0, Point3D inP1, Point3D inP2, Point3D inP3) :
    mP0(inP0),
    mP1(inP1),
    mP2(inP2),
    mP3(inP2)
{

}
BezierCurve::~BezierCurve()
{

}

void BezierCurve::drawCurve(Point3D inP0, Point3D inP1, Point3D inP2, Point3D inP3, std::vector<float>& mVertices, std::vector<float>& mColors)
{
    for (float t = 0; t <= 1; t += 0.001)
    {

        float x = pow(1 - t, 3) * inP0.getX() + 3 * pow(1 - t, 2) * t * inP1.getX() + 3 * (1 - t) * pow(t, 2) * inP2.getX() + pow(t, 3) * inP3.getX();
        float y = pow(1 - t, 3) * inP0.getY() + 3 * pow(1 - t, 2) * t * inP1.getY() + 3 * (1 - t) * pow(t, 2) * inP2.getY() + pow(t, 3) * inP3.getY();
        float z = pow(1 - t, 3) * inP0.getZ() + 3 * pow(1 - t, 2) * t * inP1.getZ() + 3 * (1 - t) * pow(t, 2) * inP2.getZ() + pow(t, 3) * inP3.getZ();

        mVertices.push_back(x);
        mVertices.push_back(y);
        mVertices.push_back(z);

        mVertices.push_back(x);
        mVertices.push_back(y);
        mVertices.push_back(z);

        mColors.push_back(0.0f);
        mColors.push_back(1.0f);
        mColors.push_back(0.0f);

        mColors.push_back(0.0f);
        mColors.push_back(1.0f);
        mColors.push_back(0.0f);

    }

}