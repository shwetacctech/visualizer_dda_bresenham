# SimpleDDA Class

The `SimpleDDA` class provides functionalities to draw lines and grids using the Digital Differential Analyzer (DDA) algorithm.

## Overview

The `SimpleDDA` class offers the following features:

- Drawing lines using the Simple DDA algorithm.
- Drawing grid lines for visualization purposes.

## Contents

The repository includes the following files:

- `SimpleDDA.h`: Header file containing the `SimpleDDA` class definition.
- `Line.h`: Header file for the `Line` class.
- Other necessary files.

## Usage

### Integration into your Project

1. **Include Header Files:** Include `SimpleDDA.h` and `Line.h` header files in your project to use the `SimpleDDA` class and `Line` class functionalities.

    ```cpp
    #include "SimpleDDA.h"
    #include "Line.h"
    ```

2. **Usage Example:**

    ```cpp
    // Example usage to draw a line using SimpleDDA

    // Create a Line object (line) and vectors for vertices and colors
    Line line(/* Define line parameters */);
    std::vector<float> vertices; // Fill vertices vector with points
    std::vector<float> colors;  // Fill colors vector with colors

    // Instantiate SimpleDDA object and draw the line
    SimpleDDA simpleDDA(line, vertices, colors);
    simpleDDA.drawGrid(vertices, colors); // Draw grid
    simpleDDA.drawLineBySimpleDDA(line, vertices); // Draw line using Simple DDA algorithm
    ```

### Dependencies

- The `SimpleDDA` class might depend on other libraries or components specified in the project.

![image](https://github.com/shwetacctech/visualizer_dda_bresenham/assets/149310316/07222d4c-ff23-497b-812e-23b3afbe86d6)
