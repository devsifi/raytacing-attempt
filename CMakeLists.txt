cmake_minimum_required(VERSION 3.12)
project(ray)

add_subdirectory(third_party/stb)

add_executable(ray 
    src/vec3.cpp
    src/main.cpp
)
target_link_libraries(ray stb)