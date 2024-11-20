cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

project(soulknight)

# Set paths for OpenCV, SFML, and matplotlib-cpp
set(CMAKE_CXX_STANDARD 14)
set(SFML_ROOT "/Users/quannguyennam/Documents/Projects/KANS/SFML-2.6.1/build")

# Find required packages
find_package(SFML 2.6 COMPONENTS system window graphics REQUIRED)

# Python dependencies (assuming Python3 is installed and properly set up)
find_package(Python3 COMPONENTS Development REQUIRED)

# Include directories
include_directories(${SFML_INCLUDE_DIR})

# Add the main executable
file(GLOB_RECURSE SOURCES_CPP src/*.cpp)
file(GLOB_RECURSE SOURCES_H src/*.h)

# Add the main file explicitly, if it's in the src folder
set(MAIN_FILE src/main.cpp)

# Combine main file with other sources
set(SOURCES ${MAIN_FILE} ${SOURCES_CPP} ${SOURCES_H})

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCES})
# Link libraries
target_link_libraries(${PROJECT_NAME} 
    sfml-system 
    sfml-window 
    sfml-graphics 
    sfml-network 
    sfml-audio 
)

# Set C++ standard to C++17
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

# Handle MSVC specific settings
if(MSVC)
    file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
    add_custom_command(TARGET ${PROJECT_NAME}
                       POST_BUILD
                       COMMAND ${CMAKE_COMMAND} -E copy_if_different
                       ${TORCH_DLLS}
                       $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif()
