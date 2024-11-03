cmake_minimum_required(VERSION 3.10)
project(CppMongoose)

set(CMAKE_CXX_STANDARD 17)

# Include directories for your project
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/exceptions)
include_directories(/usr/local/include/mongocxx/v_noabi)
include_directories(/usr/local/include/bsoncxx/v_noabi)

# Specify directories for libmongocxx and libbsoncxx
set(CMAKE_PREFIX_PATH "/usr/local/Cellar/mongo-cxx-driver/3.10.2")

# Find packages
find_package(Boost REQUIRED)
find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)

# Include directories for Boost
include_directories(${Boost_INCLUDE_DIRS})

# Source files
file(GLOB_RECURSE SRC_FILES
        "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

# Create a static or shared library
add_library(CppMongoose STATIC ${SRC_FILES})

# Link libraries to the library
target_link_libraries(CppMongoose
        PRIVATE
        ${Boost_LIBRARIES}
        ${LIBMONGOCXX_LIBRARIES}
        ${LIBBSONCXX_LIBRARIES}
        /usr/local/lib/libmongocxx.dylib
        /usr/local/lib/libbsoncxx.dylib
)