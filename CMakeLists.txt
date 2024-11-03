cmake_minimum_required(VERSION 3.10)
project(CppMongoose)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/development/include)
include_directories(${CMAKE_SOURCE_DIR}/development/src)

file(
        GLOB_RECURSE SRC_FILES
        "${CMAKE_SOURCE_DIR}/development/src*.cpp"
)
add_executable(MyChatApp ${SRC_FILES} main.cpp)