#include <gtest/gtest.h>

#include <vector>
#include <algorithm>
#include <random>
#include <limits> 
#include <chrono>

#include "../sorting.h"

std::vector<int> generateRandomVector(size_t N, int min, int max) {
    std::vector<int> v(N);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);

    for (size_t i = 0; i < N; ++i) {
        v[i] = dis(gen);
    }
    return v;
}

TEST(TestInsertionSort, TestInsertionSortRandom) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 999);

    constexpr int minVal = std::numeric_limits<int>::min(); 
    constexpr int maxVal = std::numeric_limits<int>::max(); 

    for (size_t i = 0; i < 100; ++i)
    {
        size_t N = dis(gen);
        std::vector<int> data = generateRandomVector(N, minVal, maxVal);
        std::vector<int> resulted = insertion_sort(data);
        std::sort(data.begin(), data.end());

        EXPECT_EQ(resulted, data);
    }
}

TEST(TestSelectionSort, TestSelectionSortRandom) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 999);

    constexpr int minVal = std::numeric_limits<int>::min();
    constexpr int maxVal = std::numeric_limits<int>::max();

    for (size_t i = 0; i < 100; ++i)
    {
        size_t N = dis(gen);
        std::vector<int> data = generateRandomVector(N, minVal, maxVal);
        std::vector<int> resulted = selection_sort(data);
        std::sort(data.begin(), data.end());

        EXPECT_EQ(resulted, data);
    }
}

//TEST(TestInsertionSort, TestInsertionSortSpeed) {
//    constexpr int minVal = std::numeric_limits<int>::min(); 
//    constexpr int maxVal = std::numeric_limits<int>::max(); 
//
//    size_t countRuns = 100000;
//
//    std::vector<int> data = generateRandomVector(100, minVal, maxVal);
//    long long totalDuration = 0;
//    for (int i = 0; i < countRuns; ++i) {
//        std::vector<int> dataToSort = data;  
//
//        auto start = std::chrono::high_resolution_clock::now();
//        insertion_sort(dataToSort);
//        auto end = std::chrono::high_resolution_clock::now();
//
//        totalDuration += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
//    }
//    std::cout << "Speed for insertion sort function: " << (totalDuration / countRuns) << std::endl;
//
//    totalDuration = 0;
//    for (int i = 0; i < countRuns; ++i) {
//        std::vector<int> dataToSort = data;  
//
//        auto start = std::chrono::high_resolution_clock::now();
//        std::sort(dataToSort.begin(), dataToSort.end());
//        auto end = std::chrono::high_resolution_clock::now();
//
//        totalDuration += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
//    }
//    std::cout << "Speed for std::sort: " << (totalDuration / countRuns) << std::endl;
//
//    EXPECT_EQ(1, 1);
//}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}