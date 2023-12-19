#include "pch.h"
#pragma once
#include "Line.h"

#include <vector>

class BRESENHAMS_API Bresenhams
{
public:
    Bresenhams(Line l, std::vector<float>& pixelVertices);
    ~Bresenhams();
private:
    void pixelData(Line l, std::vector<float>& pixelVertices);
};