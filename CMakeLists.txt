cmake_minimum_required(VERSION 3.16)
project("snake")

add_executable(snake main.cpp view.cpp game.cpp control.cpp)
set_property(TARGET snake PROPERTY CXX_STANDARD 20)
