#include "stdafx.h"
#include "SimpleDDA.h"

SimpleDDA::SimpleDDA() {

}

SimpleDDA::~SimpleDDA() {

}

void SimpleDDA::drawLineBySimpleDDA(Line& line, QVector<QVector2D>& pixelVertices)
{
    float dx = abs(line.getP2().x() - line.getP1().x());
    float dy = abs(line.getP2().y() - line.getP1().y());
    float steps = dx > dy ? dx : dy;
    float xInc = dx / steps;
    float yInc = dy / steps;


    while (line.getP1().x() < line.getP2().x())
    {
        pixelVertices.append(QVector2D(round(line.getP1().x()), round(line.getP1().y())));
        pixelVertices.append(QVector2D(round(line.getP1().x()) + 1, round(line.getP1().y())));
        pixelVertices.append(QVector2D(round(line.getP1().x()) + 1, round(line.getP1().y()) + 1));
        pixelVertices.append(QVector2D(round(line.getP1().x()), round(line.getP1().y()) + 1));
        line.getP1().setX(xInc + line.getP1().x());
        line.getP1().setY(yInc + line.getP1().y());
    }

   
}

