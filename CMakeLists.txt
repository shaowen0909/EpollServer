cmake_minimum_required(VERSION 3.15)
project(EpollServer)
set(CMAKE_CXX_STANDARD 11)

link_libraries(pthread)

add_executable(EpollServer src/ExampleClient.cpp main.cpp)