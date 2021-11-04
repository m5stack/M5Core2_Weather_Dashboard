#ifndef __WEATHER_MODEL_H
#define __WEATHER_MODEL_H

#include "Common/DataProc/DataProc.h"

namespace Page
{

class WeatherModel
{
public:
    HAL::Weather_Info_t weather;

public:
    void Init();
    void Deinit();
    bool GetWiFiStatus();
    int WeatherStatusUpdate();

private:
    Account* account;

private:
    static int onEvent(Account* account, Account::EventParam_t* param);
};

}

#endif
