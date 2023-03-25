# Specify the minimum version of CMake required to configure the project
cmake_minimum_required(VERSION 3.8)

# Define the name of the project
project("Cookieat")

# Set the C++ standard to use
set(CMAKE_CXX_STANDARD 17)

# Set the output directories for the build artifacts
# (object files, libraries, and executables) to a common directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

# Include the OpenXLSX library as a subdirectory
# This tells CMake to look for a CMakeLists.txt file in the OpenXLSX directory
# and build the library as part of the project
add_subdirectory(OpenXLSX)

# Create an executable target named Cookieat, which depends on the source files
# Cookieat.cpp and Cookieat.h
add_executable(Cookieat "Cookieat.cpp" "Cookieat.h")

# Link the OpenXLSX library to the Cookieat executable target
# using the target alias OpenXLSX::OpenXLSX
target_link_libraries(Cookieat OpenXLSX::OpenXLSX)

