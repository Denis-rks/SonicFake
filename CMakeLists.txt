cmake_minimum_required(VERSION 3.15)
project(SonicFake C)

set(CMAKE_C_STANDARD 17)

# SDL3
find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)

set(MACOSX_BUNDLE YES)
set(MACOSX_BUNDLE_INFO_PLIST ${CMAKE_SOURCE_DIR}/Info.plist)

add_executable(SonicFake main.c
        game.c
        game.h
        window.c
        window.h)

# SDL Libraries einbinden
target_link_libraries(SonicFake PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)