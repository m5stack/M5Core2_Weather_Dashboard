#ifndef __WEATHER_PRESENTER_H
#define __WEATHER_PRESENTER_H

#include "WeatherView.h"
#include "WeatherModel.h"

namespace Page
{

class Weather : public PageBase
{
public:
    typedef struct
    {
        uint16_t time;
        lv_color_t color;
    } Param_t;

public:
    Weather();
    virtual ~Weather();

    virtual void onCustomAttrConfig();
    virtual void onViewLoad();
    virtual void onViewDidLoad();
    virtual void onViewWillAppear();
    virtual void onViewDidAppear();
    virtual void onViewWillDisappear();
    virtual void onViewDidDisappear();
    virtual void onViewDidUnload();

private:
    void Update();
    void AttachEvent(lv_obj_t* obj);
    static void onTimerUpdate(lv_timer_t* timer);
    static void onEvent(lv_event_t* event);

private:
    WeatherView View;
    WeatherModel Model;
    lv_timer_t* timer;
};

}

#endif
