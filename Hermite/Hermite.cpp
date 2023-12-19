
#include "pch.h"
#include "Point3D.h"
#include "Hermite.h"
#include <vector>

Hermite::Hermite(Point3D inP0, Point3D inP1, Point3D inP2, Point3D inP3) :
    mP0(inP0),
    mP1(inP1),
    mP2(inP2),
    mP3(inP3)
{

}

Hermite::~Hermite()
{

}

void Hermite::drawCurve(Point3D inP0, Point3D inP1, Point3D inP2, Point3D inP3, std::vector<float>& mVertices, std::vector<float>& mColors)
{
    float t;
    float t2;
    float t3;
    for (t = 0; t <= 1; t += 0.001)
    {
        t2 = t * t;
        t3 = t2 * t;

        float blend1 = (2 * t3) - (3 * t2) + 1;
        float blend2 = (-2 * t3) + (3 * t2);
        float blend3 = t3 - (2 * t2) + t;
        float blend4 = t3 - t2;

        float x = blend1 * inP0.getX() + blend2 * (inP1.getX() - inP0.getX()) + blend3 * inP2.getX() + blend4 * (inP3.getX() - inP2.getX());
        float y = blend1 * inP0.getY() + blend2 * (inP1.getY() - inP0.getY()) + blend3 * inP2.getY() + blend4 * (inP3.getY() - inP2.getY());
        float z = blend1 * inP0.getZ() + blend2 * (inP1.getZ() - inP0.getZ()) + blend3 * inP2.getZ() + blend4 * (inP3.getZ() - inP2.getZ());

        mVertices.push_back(x);
        mVertices.push_back(y);
        mVertices.push_back(z);

        mColors.push_back(0.0f);
        mColors.push_back(1.0f);
        mColors.push_back(0.0f);

    }

}