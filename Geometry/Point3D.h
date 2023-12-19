#pragma once
#include "pch.h"

class GEOMETRY_API Point3D
{
private:
    double x, y, z;

public:
    // Constructors
    Point3D();
    Point3D(double x_coord, double y_coord, double z_coord);

    // Getter methods
    double getX() const;
    double getY() const;
    double getZ() const;

    // Setter methods
    void setX(double x_coord);
    void setY(double y_coord);
    void setZ(double z_coord);

};

