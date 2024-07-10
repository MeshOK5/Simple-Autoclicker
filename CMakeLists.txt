cmake_minimum_required(VERSION 3.25)
project(Autoclicker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static -lpthread")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(autoclicker main.cpp)
target_link_libraries(autoclicker)
