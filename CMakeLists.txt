cmake_minimum_required(VERSION 3.6)

project(color)

add_library(${PROJECT_NAME} STATIC color.c)

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES color.h DESTINATION include)
