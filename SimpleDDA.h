#pragma once
#pragma once
#include "Line.h"
#include <QVector2D.h>
class SimpleDDA
{
public:
	SimpleDDA();
	~SimpleDDA();	

public:
	void drawLineBySimpleDDA(Line& line, QVector<QVector2D>& pixelVertices);


};
