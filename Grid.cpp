#include "stdafx.h"
#include "Grid.h"


Grid::Grid() {

}

Grid::~Grid() {

}

void Grid::drawGrid(float size,float step, QVector<GLfloat>& vertices, QVector<GLfloat>& colors) {
    const float gridSize = size;

    for (float y = -gridSize / 2.0f; y <= gridSize / 2.0f; y += step)
    {
        vertices << -gridSize / 2.0f << y;
        vertices << gridSize / 2.0f << y;

        colors << 1.0f << 1.0f << 1.0f;
        colors << 1.0f << 1.0f << 1.0f;
    }

    for (float x = -gridSize / 2.0f; x <= gridSize / 2.0f; x += step)
    {
        vertices << x << -gridSize / 2.0f;
        vertices << x << gridSize / 2.0f;

        colors << 1.0f << 1.0f << 1.0f;
        colors << 1.0f << 1.0f << 1.0f;
    }
}