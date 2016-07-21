cmake_minimum_required(VERSION 3.5)
project(revisions)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp utils.h divers.h chap3.h subset.h knightTour.h back_maze.h back_nqueens.h xorList.h sumfromfile.h eratosthenes.h merge_intervals.h generatePalindromes.h blackshapes.h maxproduct.h colorful.h searchMatrix.h simplifyPath.h nextgreater.h generateSums.h validsudoku.h fraction_decimal.h peak.h)
add_executable(revisions ${SOURCE_FILES})