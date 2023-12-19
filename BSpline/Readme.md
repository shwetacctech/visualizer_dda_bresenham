# BSpline Class

The `BSpline` class is designed to perform B-spline curve evaluations based on control points and a parameter `t`.

## Overview

The `BSpline` class offers the following features:

- Evaluation of B-spline curves.
- Calculation based on control points and parameter `t`.

## Contents

The repository includes the following files:

- `BSpline.h`: Header file containing the `BSpline` class definition.
- `Point3D.h`: Header file for the `Point3D` class.
- `pch.h`: Precompiled header (if applicable).
- Other necessary files.

## Usage

### Integration into your Project

1. **Include Header Files:** Include `BSpline.h` and `Point3D.h` header files in your project to use the `BSpline` class and `Point3D` class functionalities.

    ```cpp
    #include "BSpline.h"
    #include "Point3D.h"
    ```

2. **Usage Example:**

    ```cpp
    // Example usage to evaluate B-spline curve using BSpline

    // Create a BSpline object with a specified degree
    int degree = /* specify degree */;
    BSpline bspline(degree);

    // Prepare a vector of control points (control_points) and a parameter (t)
    std::vector<Point3D> control_points; // Fill control_points vector with Point3D objects
    float t = /* specify parameter */;

    // Evaluate the B-spline curve using control points and parameter t
    std::vector<Point3D> curve_points = bspline.evaluate(control_points, t);

    // Use the generated curve_points for further operations
    ```

### Dependencies

- The `BSpline` class might depend on other libraries or components specified in the project.


![image](https://github.com/shwetacctech/visualizer_dda_bresenham/assets/149310316/0411ff33-3ff8-48dc-add4-9bed5a603fa1)
