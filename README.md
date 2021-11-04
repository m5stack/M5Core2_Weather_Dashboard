# M5Core2 Weather Dashboard Demo

Based on [LVGL](https://github.com/lvgl/lgl) and [X-TRACK](https://github.com/FASTSHIFT/X-TRACK).

### Before compile
Because CPP does not support flexible array member, you need to modify the definitions in the three header files of the weather_seniverse sub-repository before compiling.

**components -> weather_seniverse -> include -> seniverse_weather_parse**

```C
// seniverse_weather_daily.h
struct weather_daily {
    struct seniverse_weather_common common;
    struct weather_daily_item items[];  // Specify a size
};
// seniverse_weather_hourly.h
struct weather_hourly {
    struct seniverse_weather_common common;
    struct weather_hourly_item items[]; // Specify a size
};
// seniverse_weather_now.h
struct weather_now {
    struct seniverse_weather_common common;
    struct weather_now_item items[];    // Specify a size
};
```

### Menuconfig

```shell
idf.py menuconfig
```
Config the **Seniverse Configuration**

Config the **M5Stack Weather Configuration**