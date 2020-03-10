cmake_minimum_required(VERSION 3.12)
project(ray)

add_subdirectory(third_party/stb)

add_executable(ray 
    src/vec3.h
    src/ray.h
    src/camera.h
    src/hittable.h
    src/hittable_list.h
    src/shapes/sphere.h
    
    src/vec3.cpp
    src/ray.cpp
    src/camera.cpp
    src/shapes/sphere.cpp
    src/hittable_list.cpp
    src/main.cpp
)
target_link_libraries(ray stb)