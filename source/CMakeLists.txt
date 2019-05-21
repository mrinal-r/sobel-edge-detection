cmake_minimum_required(VERSION 3.12)
project(sobelEdgeDetector)

set(CMAKE_CXX_STANDARD 14)

add_executable(sobelEdgeDetector main.cpp sobel.cpp sobel.h)

find_package( OpenCV 3.3.0 REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries( sobelEdgeDetector ${OpenCV_LIBS})