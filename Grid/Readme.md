# Grid Class

The `Grid` class, marked with the `GRID_API` macro, generates a grid of horizontal and vertical lines based on a specified grid size. This class is designed to populate vertices and colors vectors with coordinates and colors for rendering a grid in a graphical application.

## Introduction

The `Grid` class provides a simple interface to create and manage grid data for rendering purposes.

## Usage

### Constructor

```
Grid::Grid(std::vector<float>& vertices, std::vector<float>& colors, int gridSize)
```
# Grid Class

The `Grid` class, marked with the `GRID_API` macro, generates a grid of horizontal and vertical lines based on a specified grid size. This class is designed to populate vertices and colors vectors with coordinates and colors for rendering a grid in a graphical application.

## Introduction

The `Grid` class provides a simple interface to create and manage grid data for rendering purposes.

## Usage

### Constructor

```
Grid::Grid(std::vector<float>& vertices, std::vector<float>& colors, int gridSize)
```
- Parameters:
vertices: A vector to store grid vertices' coordinates.
colors: A vector to store colors corresponding to grid vertices.
gridSize: An integer specifying the size of the grid.
Private Method
```
void storeGrid(std::vector<float>& vertices, std::vector<float>& colors, int gridSize)
```
Generates grid vertices and colors based on the provided parameters.

Parameters:
vertices: A vector to store grid vertices' coordinates.
colors: A vector to store colors corresponding to grid vertices.
gridSize: An integer specifying the size of the grid.
