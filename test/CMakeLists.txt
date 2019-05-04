cmake_minimum_required(VERSION 3.0)

project(swim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE "Debug")

add_executable(swim
			testingsetup.cpp
			test_io.cpp)

target_link_libraries(swim pthread  boost_unit_test_framework boost_program_options boost_system sailfish)

