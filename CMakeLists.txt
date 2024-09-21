cmake_minimum_required(VERSION 3.28.3)
project(Space-Hero)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_subdirectory(thirdparty/SDL)

file(GLOB MAIN_src
    "src/*.c" 
    "src/*/*.c"
    "src/*/*/*.c")

add_executable(Space-Hero ${MAIN_src})
target_include_directories(Space-Hero PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/ ${CMAKE_CURRENT_SOURCE_DIR}/deps/)
target_link_libraries(Space-Hero PRIVATE m SDL3::SDL3)