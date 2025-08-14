cmake_minimum_required(VERSION 3.8)

# Подтягиваем GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
# Чтобы GTest не пытался сам переопределить CRT в MSVC
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Тестовый исполняемый файл
add_executable(sorting_tests
    test_sorting.cpp
)

# Линкуем с библиотекой и GoogleTest
target_link_libraries(sorting_tests
    PRIVATE
        sorting
        gtest_main
)

# Регистрируем тесты
include(GoogleTest)
gtest_discover_tests(sorting_tests)
