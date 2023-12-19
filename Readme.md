# Visualizer Project with Qt, OpenGL, and C++

This project is a visualizer that uses Qt, OpenGL, and C++ to create a graphical interface for drawing curves and lines using various algorithms.

## Overview

The project includes functionalities to visualize and draw different types of curves and lines:

- B-Spline curves using the provided `BSpline` DLL.
- Bezier curves using the provided `BezierCurve` DLL.
- Hermite curves using the provided `Hermite` DLL.
- Line drawing using Bresenham's line drawing algorithm.
- Line drawing using Simple DDA (Digital Differential Analyzer) algorithm.
- Additional functionalities for grid drawing using Bresenham's algorithm.

## Contents

The repository includes the following files:

- Qt project files and configurations.
- Source code files written in C++.
- Precompiled headers (`pch.h`).
- DLLs for B-Spline, Bezier, and Hermite curve calculations.
- Headers for curve classes (`BSpline.h`, `BezierCurve.h`, `Hermite.h`).
- Line drawing algorithms (`Bresenhams.h`, `SimpleDDA.h`).
- Other necessary files specific to the project.

## Usage

### Dependencies

The project relies on the following components:

- Qt framework and libraries.
- OpenGL for rendering.
- Provided DLLs for B-Spline, Bezier, and Hermite curves.
- Bresenham's and Simple DDA line drawing algorithms.

### Setup Instructions

1. **Clone the Repository:** Clone this repository to your local machine.

2. **Build the Project:** Use Qt Creator or any C++ IDE that supports Qt projects to build the application.

3. **Run the Application:** Run the executable to open the visualizer.

### Drawing Curves and Lines

The application offers functionalities to draw different curves and lines:

- B-Spline: Use the `BSpline` curve drawing tool to create B-Spline curves.
- Bezier: Utilize the `BezierCurve` tool to draw Bezier curves.
- Hermite: Use the `Hermite` curve option for drawing Hermite curves.
- Bresenham's Line: Draw lines using the Bresenham's line drawing algorithm.
- Simple DDA Line: Use the Simple DDA algorithm for line drawing.

