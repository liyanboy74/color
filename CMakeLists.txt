cmake_minimum_required(VERSION 3.6)

project(color)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

add_library(${PROJECT_NAME} color.c)

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES color.h DESTINATION include)
