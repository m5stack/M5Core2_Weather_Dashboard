#include "WeatherModel.h"

using namespace Page;

void WeatherModel::Init()
{
    account = new Account("WeatherModel", DataProc::Center(), 0, this);
    account->Subscribe("StatusBar");
    account->Subscribe("WiFi");
    account->Subscribe("Weather");
    account->SetEventCallback(onEvent);
}

void WeatherModel::Deinit()
{
    if (account)
    {
        delete account;
        account = nullptr;
    }
}

bool WeatherModel::GetWiFiStatus()
{
    HAL::WiFi_Info_t wifi;
    account->Pull("WiFi", &wifi, sizeof(wifi));
    return wifi.isConnected;
}

int WeatherModel::WeatherStatusUpdate()
{
    return account->Pull("Weather", &weather, sizeof(weather));
}


int WeatherModel::onEvent(Account* account, Account::EventParam_t* param)
{
    if (param->event != Account::EVENT_PUB_PUBLISH)
    {
        return Account::ERROR_UNSUPPORTED_REQUEST;
    }
    return 0;
}