cmake_minimum_required(VERSION 3.20)
project(lectures)

set(CMAKE_CXX_STANDARD 20)

file(GLOB LECTURES "lecture*.cpp")

foreach(src ${LECTURES})
    get_filename_component(name ${src} NAME_WE)
    add_executable(${name} ${src})
endforeach()

add_executable(main main.cpp)
