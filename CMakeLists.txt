# Establish the minimum required version
cmake_minimum_required(VERSION 3.10)

# Set the name of the project and supported languages
project(raytracing4life CXX)

# Set the variables
set(SOURCES src/main.cpp) 
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Target definitions
add_executable(raytracing4life ${SOURCES})

# Include files relative to the root source directory with a <> pair
target_include_directories(raytracing4life PRIVATE ${INCLUDE_DIR})

# Specify the C++ standard library features we depend on
target_compile_features(raytracing4life PRIVATE cxx_std_17)
