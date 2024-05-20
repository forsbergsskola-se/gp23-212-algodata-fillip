#include "pch.h"
#include <vector>           // Ensure all necessary libraries are included
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "TurboCollection.h"  // Check this file for correct implementation and path

using namespace testing;  // Import the testing namespace




TEST(BubbleFunction, CorrectlySortsIntegers) {
    std::vector<int> TestList = { 6, 5, 6, 8, 2 ,1  };

    bubbleSort(TestList);  // Assuming Sort is defined in TurboCollection.h

    EXPECT_THAT(TestList, ElementsAre(1 ,2 ,5, 6, 6, 8));
}

TEST(SortFunction, CorrectlySortsIntegers) {
    std::vector<int> TestList = { 6, 5, 6, 8, 2 ,1 };

    sortSelection(TestList);  // Assuming Sort is defined in TurboCollection.h

    EXPECT_THAT(TestList, ElementsAre(1, 2, 5, 6, 6, 8));
}

TEST(QuickFunction, CorrectlySortsIntegers) {
    std::vector<int> TestList = { 6, 5, 6, 8, 2 ,1 };

    quickSort(TestList, 0, TestList.size() - 1);  // Assuming Sort is defined in TurboCollection.h

    EXPECT_THAT(TestList, ElementsAre(1, 2, 5, 6, 6, 8));
}

#include <gtest/gtest.h>

TEST(BinarySearchTest, TargetFound) {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int result = binarySearch(arr, 9, 4);
    EXPECT_EQ(result, 3);
}

TEST(BinarySearchTest, TargetNotFound) {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int result = binarySearch(arr, 9, 10);
    EXPECT_EQ(result, -1);
}

TEST(BinarySearchTest, NegativeNumbers) {
    int arr[] = { -9, -3, 0, 1, 4 };
    int result = binarySearch(arr, 5, -3);
    EXPECT_EQ(result, 1);
}

TEST(BinarySearchTest, SingleElementFound) {
    int arr[] = { 5 };
    int result = binarySearch(arr, 1, 5);
    EXPECT_EQ(result, 0);
}

TEST(BinarySearchTest, SingleElementNotFound) {
    int arr[] = { 5 };
    int result = binarySearch(arr, 1, -5);
    EXPECT_EQ(result, -1);
}


