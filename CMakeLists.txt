cmake_minimum_required(VERSION 3.26)
project(audio_stream)

set(CMAKE_CXX_STANDARD 11)

set(PORTAUDIO_DIR /opt/homebrew/Cellar/portaudio/19.7.0)
include_directories(${PORTAUDIO_DIR}/include)
link_directories(${PORTAUDIO_DIR}/lib)

add_executable(audio_stream main.cpp
        audio.cpp
        audio.h
)
target_link_libraries(audio_stream portaudio)
