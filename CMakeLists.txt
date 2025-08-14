cmake_minimum_required(VERSION 3.8)

project(alg)

add_subdirectory(sorting)

# Основной исполняемый файл
add_executable(alg alg.cpp alg.h)

if(CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET alg PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(alg PRIVATE sorting)

