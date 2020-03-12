cmake_minimum_required(VERSION 2.8.12)
project(bench CXX)

add_subdirectory(Celero)

add_executable(bench ${CMAKE_SOURCE_DIR}/src/main.cpp)
set_property(TARGET bench PROPERTY CXX_STANDARD 17)

target_include_directories(bench PRIVATE ${CONAN_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/src/ ${CMAKE_SOURCE_DIR}/src/include ${CELERO})
target_link_libraries(bench PRIVATE celero)
