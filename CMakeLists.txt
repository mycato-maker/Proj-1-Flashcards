cmake_minimum_required(VERSION 4.4.2)

project(Flashcard LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB FLASHCARD_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

if(NOT FLASHCARD_SOURCES)
    message(FATAL_ERROR "No C++ source files found in ${CMAKE_CURRENT_SOURCE_DIR}")
endif()

add_executable(Flashcard ${FLASHCARD_SOURCES})

target_include_directories(Flashcard
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
