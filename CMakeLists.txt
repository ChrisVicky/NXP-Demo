cmake_minimum_required(VERSION 3.10)
project(lvgl)
set(CMAKE_C_STANDARD 11)#C11
set(CMAKE_CXX_STANDARD 17)#C17
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(LV_CONF_BUILD_DISABLE_DEMOS TRUE)
set(LV_CONF_BUILD_DISABLE_EXAMPLES TRUE)

# IF(CMAKE_SYSTEM_NAME MATCHES "Windows")
# 	set(SDL2_DIR x86_64-w64-mingw32)
# ENDIF

# Debug Flag
set(CMAKE_BUILD_TYPE Debug)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})

INCLUDE_DIRECTORIES(music/custom)
INCLUDE_DIRECTORIES(music/generated)
INCLUDE_DIRECTORIES(music/import)
INCLUDE_DIRECTORIES(music/generated/guider_fonts)
INCLUDE_DIRECTORIES(lvgl/src)
INCLUDE_DIRECTORIES(${SDL2_DIR}/include)

# INCLUDE_DIRECTORIES(music)

link_directories(${SDL2_DIR}/bin)

file(GLOB_RECURSE INCLUDES "./*.h" )

file(GLOB_RECURSE CUSTOMS "./music/*.c")

add_subdirectory(lvgl)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}) 
SET(CMAKE_CXX_FLAGS "-O3")

find_package(SDL2 REQUIRED SDL2)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(main main.c mouse_cursor_icon.c ${SOURCES} ${CUSTOMS} ${INCLUDES})

add_compile_definitions(LV_CONF_INCLUDE_SIMPLE)

target_link_libraries(main PRIVATE lvgl ${SDL2_LIBRARIES})

add_custom_target (run COMMAND ${EXECUTABLE_OUTPUT_PATH}/main)
