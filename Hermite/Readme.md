# Hermite Class

The `Hermite` class is designed to compute and draw a Hermite curve using control points in 3D space.

## Overview

The `Hermite` class offers the following functionalities:

- Calculation and drawing of a Hermite curve based on control points.
- Drawing the curve using OpenGL or similar rendering libraries.

## Contents

The repository includes the following files:

- `Hermite.h`: Header file containing the `Hermite` class definition.
- `Point3D.h`: Header file for the `Point3D` class.
- `pch.h`: Precompiled header (if applicable).
- Other necessary files.

## Usage

### Integration into your Project

1. **Include Header Files:** Include `Hermite.h` and `Point3D.h` header files in your project to use the `Hermite` class and `Point3D` class functionalities.

    ```cpp
    #include "Hermite.h"
    #include "Point3D.h"
    ```

2. **Usage Example:**

    ```cpp
    // Example usage to compute and draw a Hermite curve using Hermite

    // Create Point3D objects for control points (inP0, inP1, inP2, inP3)
    Point3D inP0(/* specify coordinates */);
    Point3D inP1(/* specify coordinates */);
    Point3D inP2(/* specify coordinates */);
    Point3D inP3(/* specify coordinates */);

    // Create vectors for vertices (mVertices) and colors (mColors) to store curve data
    std::vector<float> mVertices; // Fill mVertices vector with vertex data
    std::vector<float> mColors;  // Fill mColors vector with color data

    // Instantiate Hermite object and draw the curve using control points
    Hermite hermiteCurve(inP0, inP1, inP2, inP3);
    hermiteCurve.drawCurve(inP0, inP1, inP2, inP3, mVertices, mColors);
    ```

### Dependencies

- The `Hermite` class might depend on other libraries or components specified in the project.


![image](https://github.com/shwetacctech/visualizer_dda_bresenham/assets/149310316/36c61cc7-6dfd-4084-9517-ebdd993e71a5)
