#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include "stats.h"

Stats Statistics::m_sStat = { NAN, NAN, NAN };

Stats Statistics::ComputeStatistics(const std::vector<float>& data) {
    auto data_size = data.size();
    if (data_size != 0) {
        m_sStat.f32Average = std::accumulate(data.begin(), data.end(), 0.0) / data_size;

        auto iterator_max = std::max_element(std::begin(data), std::end(data));
        auto iterator_min = std::min_element(std::begin(data), std::end(data));
        m_sStat.f32Max = *iterator_max;
        m_sStat.f32Min = *iterator_min;
    }
    else
    {
        m_sStat.f32Average = NAN;
        m_sStat.f32Max = NAN;
        m_sStat.f32Min = NAN;
    }
    return m_sStat;
}

void EmailAlert::DoAlert()
{
    emailSent = true;
}

void LEDAlert::DoAlert()
{
    ledGlows = true;
}

StatsAlerter::StatsAlerter(float maxThreshold, std::vector<IAlerter*> alerters) : m_maxThreshold(maxThreshold),m_alerters(alerters)
{
}
void StatsAlerter::checkAndAlert(const std::vector<float>& data)
{
    auto iterator_max = std::max_element(std::begin(data), std::end(data));
    float max = *iterator_max;

    if (max > m_maxThreshold)
    {
        for (auto &alerter: m_alerters)
        {
            alerter->DoAlert();
        }
    }
}
