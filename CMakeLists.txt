cmake_minimum_required(VERSION 3.15)
project(OpenCV_Learning)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV 4.4.0 REQUIRED)
message("OPENCV version is ${OpenCV_VERSION}")

include_directories(${OpenCV_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/includes)
link_directories(${OpenCV_LIB_DIR})

add_executable(main_test main.cpp)
target_link_libraries(main_test ${OpenCV_LIBS})

# 模糊,灰度,Sobel过滤器
add_executable(GrayBlur GrayBlur.cpp)
target_link_libraries(GrayBlur ${OpenCV_LIBS})

# 显示直方图
add_executable(ShowHistogram ShowHistogram.cpp)
target_link_libraries(ShowHistogram ${OpenCV_LIBS})