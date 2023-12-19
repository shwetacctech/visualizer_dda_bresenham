# Geometry Class DLL
This Geometry Class DLL provides essential functionalities to work with geometric entities such as lines and points in 3D space. It encapsulates various operations for these geometric entities and aims to facilitate their usage in different projects.

## Contents
The Geometry Class DLL includes the following classes:

## Line: Represents a line in 3D space defined by two 3D points.
## Point3D: Represents a point in 3D space with coordinates (x, y, z).

### Features
The DLL offers the following functionalities:

+ Creation and manipulation of 3D lines and points.
+ Calculation of distances, slopes, intersections, and other properties related to lines and points.
+ Utility functions for handling geometric calculations and operations.

### Usage
To utilize the Geometry Class DLL in your project:

Include the DLL:
Place the DLL file (GeometryClass.dll) in your project directory or in a location accessible to your project.

Link the DLL:
In your project settings or IDE configuration, link the DLL by adding it to the dependencies or linker settings.

Include Header Files:
Include the necessary header files in your project:

cpp
```
#include "Line.h"
#include "Point3D.h"
```
Using the Classes:
Instantiate objects of Line and Point3D classes to perform geometric operations. Here's an example:

cpp
```
// Creating a line
Point3D point1(0.0, 0.0, 0.0);
Point3D point2(1.0, 1.0, 1.0);
Line line(point1, point2);
```
// Calculating distance between points
Dependencies
The Geometry Class DLL may have dependencies on certain libraries or runtime environments. <br>
Ensure that the necessary dependencies are available in your project setup for seamless integration and functionality.
