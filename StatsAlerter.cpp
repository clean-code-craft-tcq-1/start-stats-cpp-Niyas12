#include "StatsAlerter.h"
#include <iostream>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>


StatsAlerter::StatsAlerter(float maxThreshold, std::vector<IAlerter*> alerters) : m_maxThreshold(maxThreshold), m_alerters(alerters)
{
}
void StatsAlerter::checkAndAlert(const std::vector<float>& data)
{
    auto iterator_max = std::max_element(std::begin(data), std::end(data));
    float max = *iterator_max;

    if (max > m_maxThreshold)
    {
        for (auto& alerter : m_alerters)
        {
            alerter->DoAlert();
        }
    }
}
