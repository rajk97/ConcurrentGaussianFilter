cmake_minimum_required(VERSION 3.10)

# MultiThreaded Gaussian Blur with Profiling
project(mtgp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native")
set(CMAKE_BUILD_TYPE Release)

find_package(OpenCV REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(Eigen3 REQUIRED)

# Tracy Options 
option(ENABLE_TRACY "Enable Tracy Profiling" OFF)
option(TRACY_ON_DEMAND "" ON)
add_subdirectory(src/tracy)


if(ENABLE_TRACY)
    add_compile_definitions(ENABLE_TRACY_PROFILING=1)
endif()

# Include directories
include_directories(
    ${PROJECT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${EIGEN3_INCLUDE_DIR}
    ${EIGEN3_INCLUDE_DIR}/unsupported
    ${CMAKE_CURRENT_SOURCE_DIR}/src/tracy/public/tracy
)

file(GLOB SOURCES
    "src/*.cpp"
    "src/tracy/public/TracyClient.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        Eigen3::Eigen
        ${OpenCV_LIBS}
        yaml-cpp
        TracyClient
        dl 
        pthread
)
