cmake_minimum_required(VERSION 3.15)
project(SonicFake C)

set(CMAKE_C_STANDARD 17)

# SDL3
find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)

add_executable(SonicFake main.c
        game.c
        game.h
        window.c
        window.h
        entities/player.h
        entities/player.c)

if (CMAKE_C_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(SonicFake PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

# SDL Libraries einbinden
target_link_libraries(SonicFake PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)