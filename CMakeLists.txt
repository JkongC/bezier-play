cmake_minimum_required(VERSION 4.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(bezier-play)

add_executable(bezier-play)

target_sources(bezier-play PRIVATE src/main.cpp
    src/picformat/ppm.h
    src/picformat/ppm.cpp
    src/BezierPoint.h
    src/BezierPoint.cpp
    src/BezierCurve.h
    src/BezierCurve.cpp
)
target_include_directories(bezier-play PRIVATE src)

if (GNU)
    target_link_libraries(bezier-play stdc++exp)
endif()