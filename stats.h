#pragma once 

#include <vector>
#include "IAlert.h"

struct Stats
{
    float Average;
    float Min;
    float Max;
};



class Statistics
{
    static Stats m_sStat;
public:
    static Stats ComputeStatistics(const std::vector<float>& data);
};
