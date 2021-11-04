file(GLOB_RECURSE SOURCES ./*.c ./*.cpp ./App/*.c ./App/*.cpp ./App/Common/**/*.c ./App/Common/**/*.cpp
                           ./App/Pages/*.c ./App/Pages/**/*.c ./App/Pages/**/*.cpp
                           ./App/Resource/*.c ./App/Resource/*.cpp /App/Resource/**/*.c ./App/Resource/**/*.cpp
                           ./App/Utils/**.c ./App/Utils/**.cpp ./HAL/*.c ./HAL/*.cpp)

idf_component_register(SRCS ${SOURCES}
                        INCLUDE_DIRS "." "./App" "./HAL"
                        )

target_compile_definitions(${COMPONENT_LIB} PUBLIC "-DLV_HOR_RES_MAX=320")
target_compile_definitions(${COMPONENT_LIB} PUBLIC "-DLV_VER_RES_MAX=240")
target_compile_definitions(${COMPONENT_LIB} PUBLIC "-DLV_LVGL_H_INCLUDE_SIMPLE")
