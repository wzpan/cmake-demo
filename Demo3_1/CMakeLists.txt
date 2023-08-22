# CMake 最低版本号要求

cmake_minimum_required (VERSION 2.8)

# 项目信息

project (Demo3_1)

set(ALL_SOURCES CACHE INTERNAL "All sources to be compiled in this project" )

# 添加 src 子目录

add_subdirectory(src)

# 指定生成目标
include_directories(src)

add_executable(Demo main.cpp ${ALL_SOURCES})

