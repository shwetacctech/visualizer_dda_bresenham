#include "pch.h"
#include "SimpleDDA.h"

SimpleDDA::SimpleDDA(Line& line, vector<float>& mVertices, vector<float>& colors)
{
    //drawGrid(mVertices, colors);
    //drawLineBySimpleDDA(line, mVertices);
}

SimpleDDA::~SimpleDDA()
{

}


//Code to draw a grid
void SimpleDDA::drawGrid(vector<float>& vertices, vector<float>& colors)
{
    const float gridSize = 50.0f;
    const float step = 1.0f;

    // Code to draw horizontal lines
    for (float y = -gridSize / 2.0f; y <= gridSize / 2.0f; y += step)
    {
        vertices.push_back(-gridSize / 2.0f);
        vertices.push_back(y);
        vertices.push_back(0);
        vertices.push_back(gridSize / 2.0f);
        vertices.push_back(y);
        vertices.push_back(0);

    }

    // Code to draw Vertical lines
    for (float x = -gridSize / 2.0f; x <= gridSize / 2.0f; x += step)
    {
        vertices.push_back(x);
        vertices.push_back(-gridSize / 2.0f);
        vertices.push_back(0);
        vertices.push_back(x);
        vertices.push_back(gridSize / 2.0f);
        vertices.push_back(0);


    }
}

//Symmetric DDA implimentation
void SimpleDDA::drawLineBySimpleDDA(Line& line, vector<float>& mVertices)
{
    float dx = abs(line.getP2().getX() - line.getP1().getX());
    float dy = abs(line.getP2().getY() - line.getP1().getY());
    float deltaX;
    float deltaY;
    if (dy > dx)
    {
        deltaX = dx / dy;
        deltaY = dy / dy;
    }
    else
    {
        deltaX = dx / dx;
        deltaY = dy / dx;
    }
    while (line.getP1().getX() < line.getP2().getX())
    {

        line.getP1().setX(deltaX + line.getP1().getX());
        line.getP1().setY(deltaY + line.getP1().getY());
    }


}

