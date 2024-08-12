cmake_minimum_required(VERSION 3.10)
project(cmvideoediter)

set(CMAKE_CXX_STANDARD 17)

# Find FFmpeg package
find_package(PkgConfig REQUIRED)
pkg_check_modules(FFMPEG REQUIRED libavcodec libavformat libavutil libswscale)

include_directories(${FFMPEG_INCLUDE_DIRS})
link_directories(${FFMPEG_LIBRARY_DIRS})

# Define the executable
add_executable(cmvideoediter main.cpp videoeditor.cpp)

# Link the FFmpeg libraries
target_link_libraries(cmvideoediter ${FFMPEG_LIBRARIES})

# Detect Termux environment
if(EXISTS "$ENV{PREFIX}")
    # We're in Termux
    set(INSTALL_DIR "$ENV{PREFIX}/bin")
else()
    # Assume we're on a standard Linux system
    set(INSTALL_DIR "/usr/local/bin")
endif()

# Installation rules
install(TARGETS cmvideoediter DESTINATION ${INSTALL_DIR})
# Remove the following line if it's causing issues
# install(FILES README.md DESTINATION /usr/local/share/doc/cmvideoediter)
