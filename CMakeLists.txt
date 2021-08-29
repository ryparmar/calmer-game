cmake_minimum_required(VERSION 3.5)
project(calmer-game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# set(source_dir "${PROJECT_SOURCE_DIR}")
# file(GLOB source_files "${source_dir}/*.cpp")

# find_file(SDL2_INCLUDE_DIR NAME SDL.h HINTS SDL2)
# find_library(SDL2_LIBRARY NAME SDL2)

# includes cmake/FindSDL2.cmake
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
# find_library(SDL_MIXER_LIBRARY
#   NAMES SDL2_mixer
#   HINTS
#     ENV SDLMIXERDIR
#     ENV SDLDIR
#   PATH_SUFFIXES lib
# )

include(FindPkgConfig)
pkg_check_modules(SDL2_Mixer REQUIRED IMPORTED_TARGET SDL2_mixer)

include_directories(calmer-game ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS}) # ${SDL2_MIXER_INCLUDE_DIRS})

# add_executable(game ${source_files})
add_executable(calmer-game 
    src/Game.hpp
    src/Game.cpp
    src/main.cpp
)

target_link_libraries(calmer-game ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES}) # ${SDL2_MIXER_LIBRARIES})
target_link_libraries(calmer-game PkgConfig::SDL2_Mixer)

# set(THREADS_PREFER_PTHREAD_FLAG ON)
# find_package(Threads REQUIRED)
# target_link_libraries(game Threads::Threads)

if ( CMAKE_CXX_COMPILER_ID MATCHES "Clang|AppleClang|GNU" )
    target_compile_options( calmer-game PRIVATE -Wall -Wextra -Wunreachable-code -Wpedantic)
endif()
if ( CMAKE_CXX_COMPILER_ID MATCHES "MSVC" )
    target_compile_options( calmer-game PRIVATE /W4 )
endif()


if (${CMAKE_VERSION} VERSION_GREATER 3.5)
  set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT calmer-game)
endif()

