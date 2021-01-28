#include <vector>

struct Stats
{
    float f32Average;
    float f32Min;
    float f32Max;
};

class IAlerter
{

public:
    virtual void DoAlert() = 0;
};

class EmailAlert: public IAlerter
{
public:
    bool emailSent = false;
    virtual void DoAlert();
};
class LEDAlert : public IAlerter
{
public:
    bool ledGlows = false;
    virtual void DoAlert();
};

class StatsAlerter
{
private:
    float m_maxThreshold;
    std::vector<IAlerter*> m_alerters;
public:
    StatsAlerter(float maxThreshold, std::vector<IAlerter*> alerters);
    void checkAndAlert(const std::vector<float>& data);
};

class Statistics
{
    static Stats m_sStat;
public:
    static Stats ComputeStatistics(const std::vector<float>& data);
};
