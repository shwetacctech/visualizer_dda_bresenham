#pragma once
#include "pch.h"
#include "Line.h"
#include <vector>


using namespace std;

class SIMPLEDDA_API SimpleDDA
{
public:
	SimpleDDA(Line& line, vector<float>& mVertices, vector<float>& colors);
	~SimpleDDA();

public:
	void drawGrid(vector<float>& vertices, vector<float>& colors);
	void drawLineBySimpleDDA(Line& line, vector<float>& mVertices);

};
