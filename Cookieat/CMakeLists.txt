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
set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/appicon.rc")
add_executable(Cook-i-eat "Cookieat.cpp" "Cookieat.h" ${APP_ICON_RESOURCE_WINDOWS})

# Copy the resources folder to the build output directory
file(COPY ../Resources/Recipes.xlsx DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# Link the OpenXLSX library to the Cookieat executable target
# using the target alias OpenXLSX::OpenXLSX
target_link_libraries(Cook-i-eat OpenXLSX::OpenXLSX nowide::nowide)

