#ifndef __WEATHER_VIEW_H
#define __WEATHER_VIEW_H

#include "../Page.h"

namespace Page
{

class WeatherView
{
public:
    void Create(lv_obj_t* root);
    void Delete();
    void Btn_Create(lv_obj_t* par, const void* img_src, lv_coord_t x_ofs);

public:
    struct
    {
        lv_obj_t* img_weather;
        lv_obj_t* temperature;
        lv_obj_t* lastupdate;
    } ui;

private:

};

}

#endif // !__VIEW_H
