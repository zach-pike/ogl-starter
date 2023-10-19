cmake_minimum_required(VERSION 3.22.1)


set(CXX_STANDARD 20)
project(ogl-spirals)

include_directories(src/)

file(GLOB_RECURSE SRC src/*.cpp)

add_executable(main ${SRC})

target_link_libraries(main GL GLEW glfw m X11 Xi Xrandr)