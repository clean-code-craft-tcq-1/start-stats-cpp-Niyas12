#pragma once 
#include <vector>
#include "IAlert.h"

class StatsAlerter
{
private:
    float m_maxThreshold;
    std::vector<IAlerter*> m_alerters;
public:
    StatsAlerter(float maxThreshold, std::vector<IAlerter*> alerters);
    void checkAndAlert(const std::vector<float>& data);
};
