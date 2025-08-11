cmake_minimum_required(VERSION 3.8)

project(alg)
enable_testing()

# Основной исполняемый файл
add_executable(alg alg.cpp sorting.cpp sorting.h alg.h)

if(CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET alg PROPERTY CXX_STANDARD 20)
endif()

include(FetchContent)

# Отключаем тесты googletest внутри googletest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

FetchContent_MakeAvailable(googletest)

# Создаем target для тестов
add_executable(tests AlgSortingTest/test_sorting.cpp)

# Линкуем GoogleTest
target_link_libraries(tests gtest_main)

if(CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET tests PROPERTY CXX_STANDARD 20)
endif()

# Подключаем и вызываем gtest_discover_tests
include(GoogleTest)
gtest_discover_tests(tests)
