cmake_minimum_required(VERSION 3.11) 
PROJECT (opencv_wrapper CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED core imgcodecs imgproc)

add_library(opencv_wrapper SHARED
	exports.h
	mat.h
	src/mat.cpp
	src/mat_impl.h
	image_operations.h
	src/image_operations.cpp
	math.h
	src/math.cpp
	src/math_impl.h
)
target_link_libraries(opencv_wrapper PRIVATE ${OpenCV_LIBS})
