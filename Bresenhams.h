#pragma once
#include "Line.h"
#include <QVector2D.h>
class Bresenhams
{
public:
	Bresenhams();
	~Bresenhams();

public:
	void drawLineByBresenhams(Line& line, QVector<QVector2D>& pixelVertices);

};


