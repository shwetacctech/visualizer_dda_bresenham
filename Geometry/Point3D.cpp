#include "pch.h"
#include "Point3D.h"
#include <iostream>

// Constructors
Point3D::Point3D() : x(0.0), y(0.0), z(0.0) {}

Point3D::Point3D(double x_coord, double y_coord, double z_coord) : x(x_coord), y(y_coord), z(z_coord) {}

// Getter methods
double Point3D::getX() const {
    return x;
}

double Point3D::getY() const {
    return y;
}

double Point3D::getZ() const {
    return z;
}

// Setter methods
void Point3D::setX(double x_coord) {
    x = x_coord;
}

void Point3D::setY(double y_coord) {
    y = y_coord;
}

void Point3D::setZ(double z_coord) {
    z = z_coord;
}
