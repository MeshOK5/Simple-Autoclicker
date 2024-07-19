cmake_minimum_required(VERSION 3.22)
project(sfml)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast")
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "SFML-2.5.1/lib/cmake/SFML")


find_package(SFML COMPONENTS graphics audio REQUIRED)

add_executable(autoclicker main.cpp)

target_link_libraries(autoclicker sfml-graphics sfml-audio)
