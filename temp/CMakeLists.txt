cmake_minimum_required(VERSION 3.29)
project(DynamicProgramming)

set(CMAKE_CXX_STANDARD 20)

add_executable(DynamicProgramming
        HouseRobber/houseRobber.cpp
        deleteAndEarn/deleteAndEarn.cpp
        deleteAndEarn/deleteAndEarnImproved.cpp
        uniquePaths/main.cpp)
