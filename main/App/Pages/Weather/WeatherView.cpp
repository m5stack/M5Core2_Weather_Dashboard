#include "WeatherView.h"
#include <stdarg.h>
#include <stdio.h>

using namespace Page;

void WeatherView::Create(lv_obj_t* root)
{
    lv_obj_t* img = lv_img_create(root);
    lv_img_set_src(img, ResourcePool::GetImage("0"));
    lv_obj_align(img, LV_ALIGN_CENTER, 0, -40);
    ui.img_weather = img;

    lv_obj_t* label = lv_label_create(root);
    lv_obj_set_style_text_font(label, ResourcePool::GetFont("alibabasans_regular_32"), 0);
    lv_label_set_text(label, "0°C / Sunny");
    lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 30);
    lv_obj_set_style_text_color(label, LV_COLOR_MAKE16(0xff, 0xff, 0xff), _LV_STYLE_STATE_CMP_SAME);
    ui.temperature = label;

    label = lv_label_create(root);
    lv_obj_set_style_text_font(label, ResourcePool::GetFont("alibabasans_regular_17"), 0);
    lv_label_set_text(label, "Connecting to Wi-Fi...");
    lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL);
    lv_obj_align(label, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_set_style_text_color(label, LV_COLOR_MAKE16(0xff, 0xff, 0xff), _LV_STYLE_STATE_CMP_SAME);
    ui.lastupdate = label;
}

void WeatherView::Delete()
{

}