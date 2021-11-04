#include <cstdio>
#include "Weather.h"

using namespace Page;

Weather::Weather()
{

}

Weather::~Weather()
{

}

void Weather::onCustomAttrConfig()
{
    SetCustomCacheEnable(true);
    SetCustomLoadAnimType(PageManager::LOAD_ANIM_OVER_BOTTOM, 600, lv_anim_path_bounce);
}

void Weather::onViewLoad()
{
    Model.Init(); // DataCenter
    View.Create(root);
    AttachEvent(root);

    StatusBar::Appear(true);
}

void Weather::onViewDidLoad()
{
}

void Weather::onViewWillAppear()
{
    Param_t param;
    param.color = LV_COLOR_MAKE16(54, 123, 175);
    param.time = 1000;

    PAGE_STASH_POP(param);

    lv_obj_set_style_bg_color(root, param.color, LV_PART_MAIN);
    timer = lv_timer_create(onTimerUpdate, param.time, this);
}

void Weather::onViewDidAppear()
{
    lv_timer_resume(timer);
}

void Weather::onViewWillDisappear()
{

}

void Weather::onViewDidDisappear()
{
    lv_timer_pause(timer);
}

void Weather::onViewDidUnload()
{
    Model.Deinit();
    View.Delete();
}

void Weather::AttachEvent(lv_obj_t *obj)
{
    lv_obj_set_user_data(obj, this);
    lv_obj_add_event_cb(obj, onEvent, LV_EVENT_ALL, this);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
}

void Weather::Update()
{
    static int count = 295;
    static char buf[32];
    static char weather_code[2];

    count += 1;
    if (Model.GetWiFiStatus()) {
        if (count > 300) {  //Every 300s update
            if (Model.WeatherStatusUpdate() == 0) {
                count = 0;
                sprintf(buf, "%.1f°C / %s", (float)Model.weather.temperature, Model.weather.summary);
                // lv_label_set_text_fmt(View.ui.temperature, "%0.1f°C", (float)Model.weather.temperature); ????? Bug
                lv_label_set_text(View.ui.temperature, buf);
                lv_label_set_text_fmt(View.ui.lastupdate, "%s", Model.weather.last_update);

                // https://seniverse.yuque.com/books/share/e52aa43f-8fe9-4ffa-860d-96c0f3cf1c49/yev2c3
                itoa(Model.weather.code, weather_code, 10);
                lv_img_set_src(View.ui.img_weather, ResourcePool::GetImage(weather_code));
            } else {
                count = 290;
            }
        }
    } else {
        lv_label_set_text(View.ui.lastupdate, "Connecting to Wi-Fi...");
    }
}

void Weather::onTimerUpdate(lv_timer_t *timer)
{
    Weather *instance = (Weather *)timer->user_data;

    instance->Update();
}

void Weather::onEvent(lv_event_t *event)
{
    lv_obj_t *obj = lv_event_get_target(event);
    lv_event_code_t code = lv_event_get_code(event);
    Weather *instance = (Weather *)lv_obj_get_user_data(obj);

    if (obj == instance->root) {

        if (LV_EVENT_GESTURE == code) {
            lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
            if (LV_DIR_LEFT == dir) {
            } else if (LV_DIR_RIGHT == dir) {
                // instance->Manager->Push("Pages/_Template");
            } else if (LV_DIR_BOTTOM == dir) {
            }
        }
    }
}
