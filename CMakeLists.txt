cmake_minimum_required(VERSION 3.29)
project(dynamicPrograming)

set(CMAKE_CXX_STANDARD 14)

add_executable(dynamicPrograming
    temp/deleteAndEarn/deleteAndEarn.cpp
    temp/deleteAndEarn/deleteAndEarnImproved.cpp
    temp/HouseRobber/houseRobber.cpp
    temp/MinCostStairs/minCostStairs.cpp
    temp/minimumPathSum/main.cpp
    temp/uniquePaths/main.cpp
        temp/uniquePaths2/main.cpp)
