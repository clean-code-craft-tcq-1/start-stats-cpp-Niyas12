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
        m_sStat.Average = std::accumulate(data.begin(), data.end(), 0.0) / data_size;

        auto iterator_max = std::max_element(std::begin(data), std::end(data));
        auto iterator_min = std::min_element(std::begin(data), std::end(data));
        m_sStat.Max = *iterator_max;
        m_sStat.Min = *iterator_min;
    }
    else
    {
        m_sStat.Average = NAN;
        m_sStat.Max = NAN;
        m_sStat.Min = NAN;
    }
    return m_sStat;
}
