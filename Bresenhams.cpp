#include "stdafx.h"
#include "Bresenhams.h"

Bresenhams::Bresenhams() {
    
}

Bresenhams::~Bresenhams() {

}

void Bresenhams::drawLineByBresenhams(Line& line, QVector<QVector2D>& pixelVertices) {
    float dx = abs(line.getP2().x() - line.getP1().x());
    float dy = abs(line.getP2().y() - line.getP1().y());
    float sx = (line.getP1().x() < line.getP2().x()) ? 1.0f : -1.0f;
    float sy = (line.getP1().y() < line.getP2().y()) ? 1.0f : -1.0f;
    float err = dx - dy;
    while (line.getP1().x() < line.getP2().x() || line.getP1().y() < line.getP2().y())
    {
        pixelVertices.append(QVector2D(round(line.getP1().x()), round(line.getP1().y())));
        pixelVertices.append(QVector2D(round(line.getP1().x()) + 1, round(line.getP1().y())));
        pixelVertices.append(QVector2D(round(line.getP1().x()) + 1, round(line.getP1().y()) + 1));
        pixelVertices.append(QVector2D(round(line.getP1().x()), round(line.getP1().y()) + 1));
        float e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            line.getP1().setX(sx + line.getP1().x());
            line.getP1().setX(round(line.getP1().x()));
        }
        if (e2 < dx) {
            err += dx;
            line.getP1().setY(sy + line.getP1().y());
            line.getP1().setY(round(line.getP1().y()));
        }


    }
   
}

    

