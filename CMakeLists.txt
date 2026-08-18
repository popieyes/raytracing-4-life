# 1. Establish the minimum required version
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# 2. Set the name of the project and supported languages
project(raytracing4life CXX)

# 3. File globbing. Search for the files we are going to include in the build
file(GLOB_RECURSE sources src/*.cpp)

# 4. Target definitions
add_executable(raytracing4life ${sources})

# 5. Include files relative to the root source directory with a <> pair
target_include_directories(raytracing4life PUBLIC src)
