#pragma once
class Grid
{
public:
	Grid();
	~Grid();

	void drawGrid(float size,float step, QVector<GLfloat>& vertices, QVector<GLfloat>& colors);
};

