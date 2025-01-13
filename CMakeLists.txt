cmake_minimum_required(VERSION 3.10)
project(game)


# Add source files
add_executable(game src/main.cpp src/player.cpp src/filereader.cpp src/tilesystem.cpp src/camera.cpp src/weapon.cpp src/enemy.cpp)

# Link libraries
find_package(raylib REQUIRED)

# g++ main.cpp player.cpp -o game -lraylib -lm -ldl -lpthread -lGL -lX11
target_link_libraries(game raylib dl pthread m X11 GL)
