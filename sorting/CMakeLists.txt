cmake_minimum_required(VERSION 3.8)

add_library(sorting STATIC
	sorting.cpp
	sorting.h
)
target_compile_features(sorting PUBLIC cxx_std_20)

target_include_directories(sorting PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_subdirectory(tests)