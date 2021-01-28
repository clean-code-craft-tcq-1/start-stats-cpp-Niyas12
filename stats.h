#pragma once 

#include <vector>
#include "IAlert.h"

struct Stats
{
    float f32Average;
    float f32Min;
    float f32Max;
};



class Statistics
{
    static Stats m_sStat;
public:
    static Stats ComputeStatistics(const std::vector<float>& data);
};
