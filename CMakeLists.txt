# Copyright (c) 2015, Ruslan Baratov
# All rights reserved.

cmake_minimum_required(VERSION 3.0)

project(download-dlib)

find_package(dlib CONFIG REQUIRED)

add_executable(bayes_net_ex bayes_net_ex.cpp)
target_link_libraries(bayes_net_ex PUBLIC dlib::dlib)

add_executable(chinese_whispers_ex chinese_whispers_ex.cpp)
target_link_libraries(chinese_whispers_ex PUBLIC dlib::dlib)
