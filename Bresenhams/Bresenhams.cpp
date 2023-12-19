#include "pch.h"
#include "Bresenhams.h"
#include <vector>


Bresenhams::Bresenhams(Line l, std::vector<float>& pixelVertices)
{
    pixelData(l, pixelVertices);
}

Bresenhams::~Bresenhams()
{
}


void Bresenhams::pixelData(Line l, std::vector<float>& pixelVertices)
{
    // Bresenham's line drawing algorithm
    float x1 = l.getP1().getX();
    float y1 = l.getP1().getY();
    float x2 = l.getP2().getX();
    float y2 = l.getP2().getY();

    float dx = abs(x2 - x1);
    float dy = abs(y2 - y1);
    float sx = (x1 < x2) ? 1.0f : -1.0f;
    float sy = (y1 < y2) ? 1.0f : -1.0f;
    float err = dx - dy;

    while (x1 < x2 || y1 < y2) {
        pixelVertices.push_back(round(x1));
        pixelVertices.push_back(round(y1));
        pixelVertices.push_back(0);
        pixelVertices.push_back(round(x1) + 1);
        pixelVertices.push_back(round(y1));
        pixelVertices.push_back(0);
        pixelVertices.push_back(round(x1) + 1);
        pixelVertices.push_back(round(y1) + 1);
        pixelVertices.push_back(0);
        pixelVertices.push_back(round(x1));
        pixelVertices.push_back(round(y1) + 1);
        pixelVertices.push_back(0);

        float e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
            x1 = round(x1);
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
            y1 = round(y1);
        }
    }
}