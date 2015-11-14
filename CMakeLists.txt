cmake_minimum_required(VERSION 2.8.8)
project(GildedRose)

include_directories(include)
file(GLOB GILDEDROSE_SF "src/*")

add_library(gildedRose STATIC ${GILDEDROSE_SF})

enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(GildedRoseUnitTests test/GildedRoseUnitTests.cc)
target_link_libraries(GildedRoseUnitTests gildedRose ${GTEST_BOTH_LIBRARIES})

add_executable(GildedRoseTextTests test/GildedRoseTextTests.cc)
target_link_libraries(GildedRoseTextTests gildedRose)