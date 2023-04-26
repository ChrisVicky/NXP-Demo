cmake_minimum_required(VERSION 3.10)
project(lvgl)
set(CMAKE_C_STANDARD 11)#C11
set(CMAKE_CXX_STANDARD 17)#C17
set(CMAKE_CXX_STANDARD_REQUIRED ON)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})
INCLUDE_DIRECTORIES(custom)
INCLUDE_DIRECTORIES(generated)
INCLUDE_DIRECTORIES(import)
INCLUDE_DIRECTORIES(generated/guider_fonts)
INCLUDE_DIRECTORIES(lvgl/src)

file(GLOB_RECURSE INCLUDES "./*.h" )
file(GLOB_RECURSE CUSTOMS "./*.c")

add_subdirectory(lvgl)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin) 
SET(CMAKE_CXX_FLAGS "-O3")

find_package(SDL2 REQUIRED SDL2)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(main main.c mouse_cursor_icon.c ${SOURCES} ${CUSTOMS} ${INCLUDES})

add_compile_definitions(LV_CONF_INCLUDE_SIMPLE)
target_link_libraries(main PRIVATE lvgl lvgl::examples lvgl::demos ${SDL2_LIBRARIES})
add_custom_target (run COMMAND ${EXECUTABLE_OUTPUT_PATH}/main)
