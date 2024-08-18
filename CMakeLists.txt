cmake_minimum_required(VERSION 3.30.0)
project(Noname)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_subdirectory(thirdparty/SDL)

file(GLOB MAIN_src
    "src/*.c" 
    "src/*/*.c"
    "src/*/*/*.c")

add_executable(Noname ${MAIN_src})
target_include_directories(Noname PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/ ${CMAKE_CURRENT_SOURCE_DIR}/deps/)
target_link_libraries(Noname PRIVATE SDL2::SDL2main SDL2::SDL2-static)