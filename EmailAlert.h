#pragma once 

#include "IAlert.h"

class EmailAlert : public IAlerter
{
public:
    bool emailSent = false;
    EmailAlert();
    ~EmailAlert();
    virtual void DoAlert();
};