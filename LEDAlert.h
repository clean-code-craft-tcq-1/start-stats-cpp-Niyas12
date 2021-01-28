#pragma once 

#include "IAlert.h"

class LEDAlert : public IAlerter
{
public:
    bool ledGlows = false;
    LEDAlert();
    ~LEDAlert();
    virtual void DoAlert();
};
