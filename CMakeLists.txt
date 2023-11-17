cmake_minimum_required(VERSION 3.16)
project(mymuduo)
set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include) #指定头文件路径
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp) #搜索路径
set(LIBRARY_OUTPUT_PATH /home/xbj/FuxianCode/fuxian_mudo/mudo/lib) #指定生成库储存路径
add_library(mymuduo SHARED ${SRC}) #动态库
