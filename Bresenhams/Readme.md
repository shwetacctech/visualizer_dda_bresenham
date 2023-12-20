# Bresenhams Class

The `Bresenhams` class provides functionalities to draw lines using the Bresenham's line drawing algorithm and generate grid lines.

## Overview

The `Bresenhams` class offers the following features:

- Drawing lines using Bresenham's line drawing algorithm.
- Generating grid lines for visualization purposes.

## Contents

The repository includes the following files:

- `Bresenhams.h`: Header file containing the `Bresenhams` class definition.
- `Line.h`: Header file for the `Line` class.
- `pch.h`: Precompiled header (if applicable).
- Other necessary files.

## Usage

### Integration into your Project

1. **Include Header Files:** Include `Bresenhams.h` and `Line.h` header files in your project to use the `Bresenhams` class and `Line` class functionalities.

    ```cpp
    #include "Bresenhams.h"
    #include "Line.h"
    ```

2. **Usage Example:**

    ```cpp
    // Example usage to draw lines and grid using Bresenhams

    // Create a Line object (line) and a vector for pixel vertices
    Line line(/* specify line parameters */);
    std::vector<float> pixelVertices; // Fill pixelVertices vector with pixel coordinates

    // Instantiate Bresenhams object and draw grid and line
    Bresenhams bresenham(line, pixelVertices);
    bresenham.drawGrid(pixelVertices); // Draw grid
    // Use pixelData method to draw lines using Bresenham's algorithm
    // pixelVertices vector will be updated with line pixel coordinates
    ```

### Dependencies

- The `Bresenhams` class might depend on other libraries or components specified in the project.

![image](https://github.com/shwetacctech/visualizer_dda_bresenham/assets/149310316/2a7c0d3e-35da-4e2e-9fbd-441e034379b4)

