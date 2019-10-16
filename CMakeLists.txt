cmake_minimum_required(VERSION 2.8.12)
project(bench CXX)

# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
                  "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(CONANFILE conanfile.py
				BUILD_TYPE Release
				INSTALL_ARGS --build missing
                BASIC_SETUP)

add_executable(bench ${CMAKE_SOURCE_DIR}/src/main.cpp)
set_property(TARGET bench PROPERTY CXX_STANDARD 17)

target_include_directories(bench PRIVATE ${CONAN_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/src/)
target_link_libraries(bench PRIVATE ${CONAN_LIBS})
