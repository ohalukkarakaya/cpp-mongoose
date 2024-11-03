cmake_minimum_required(VERSION 3.10)
project(CppMongoose)

set(CMAKE_CXX_STANDARD 17)

# Include directories for your project
include_directories(
        ${CMAKE_SOURCE_DIR}/development/include
        ${CMAKE_SOURCE_DIR}/models/include
        ${CMAKE_SOURCE_DIR}/constants
        ${CMAKE_SOURCE_DIR}/exceptions/MongoSchemaException
        ${CMAKE_SOURCE_DIR}/exceptions/MongoValidationException
        ${CMAKE_SOURCE_DIR}/exceptions/NotFoundException
        /usr/local/include/mongocxx/v_noabi
        /usr/local/include/bsoncxx/v_noabi
)

# Specify directories for libmongocxx and libbsoncxx
set(CMAKE_PREFIX_PATH "/usr/local/Cellar/mongo-cxx-driver/3.10.2")

# Find packages
find_package(Boost REQUIRED)
find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)

# Include directories for Boost
include_directories(${Boost_INCLUDE_DIRS})

# Source files
file(
        GLOB_RECURSE SRC_FILES
        "${CMAKE_SOURCE_DIR}/development/src/*.cpp"
        "${CMAKE_SOURCE_DIR}/models/src/*.cpp"
        "${CMAKE_SOURCE_DIR}/exceptions/MongoSchemaException/*.cpp"
        "${CMAKE_SOURCE_DIR}/exceptions/MongoValidationException/*.cpp"
        "${CMAKE_SOURCE_DIR}/exceptions/NotFoundException/*.cpp"
)

# Define the executable
add_executable(CppMongoose main.cpp ${SRC_FILES})

# Link libraries to the executable
target_link_libraries(CppMongoose
        PRIVATE
        ${Boost_LIBRARIES}
        ${LIBMONGOCXX_LIBRARIES}
        ${LIBBSONCXX_LIBRARIES}
        /usr/local/lib/libmongocxx.dylib
        /usr/local/lib/libbsoncxx.dylib
)