cmake_minimum_required(VERSION 3.10)

# Project name and version
project(game VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Link directories (where the Raylib library is located)
link_directories(lib)
 
# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link Raylib (and other required libraries) 
target_link_libraries(${PROJECT_NAME} raylib)

set(CMAKE_BUILD_TYPE Debug)


# Platform-specific dependencies
if (UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} m pthread dl)
elseif (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL" "-framework Cocoa" "-framework IOKit" "-framework CoreVideo")
elseif (WIN32)
    target_link_libraries(${PROJECT_NAME} opengl32 gdi32 winmm)
endif()
