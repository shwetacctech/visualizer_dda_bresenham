# BezierCurve Class

The `BezierCurve` class is designed to compute and draw a Bezier curve using control points in 3D space.

## Overview

The `BezierCurve` class offers the following functionalities:

- Calculation and drawing of a Bezier curve based on control points.
- Drawing the curve using OpenGL or similar rendering libraries.

## Contents

The repository includes the following files:

- `BezierCurve.h`: Header file containing the `BezierCurve` class definition.
- `Point3D.h`: Header file for the `Point3D` class.
- `pch.h`: Precompiled header (if applicable).
- Other necessary files.

## Usage

### Integration into your Project

1. **Include Header Files:** Include `BezierCurve.h` and `Point3D.h` header files in your project to use the `BezierCurve` class and `Point3D` class functionalities.

    ```cpp
    #include "BezierCurve.h"
    #include "Point3D.h"
    ```

2. **Usage Example:**

    ```cpp
    // Example usage to compute and draw a Bezier curve using BezierCurve

    // Create Point3D objects for control points (inP0, inP1, inP2, inP3)
    Point3D inP0(/* specify coordinates */);
    Point3D inP1(/* specify coordinates */);
    Point3D inP2(/* specify coordinates */);
    Point3D inP3(/* specify coordinates */);

    // Create vectors for vertices (mVertices) and colors (mColors) to store curve data
    std::vector<float> mVertices; // Fill mVertices vector with vertex data
    std::vector<float> mColors;  // Fill mColors vector with color data

    // Instantiate BezierCurve object and draw the curve using control points
    BezierCurve bezierCurve(inP0, inP1, inP2, inP3);
    bezierCurve.drawCurve(inP0, inP1, inP2, inP3, mVertices, mColors);
    ```

### Dependencies

- The `BezierCurve` class might depend on other libraries or components specified in the project.



![image](https://github.com/shwetacctech/visualizer_dda_bresenham/assets/149310316/fc9e4b53-22d3-4ac8-b8d8-43e2daeb2017)
