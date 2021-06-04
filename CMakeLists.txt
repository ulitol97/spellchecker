cmake_minimum_required(VERSION 3.15)
project(spellchecker)
set(CMAKE_CXX_STANDARD 17)
include_directories(src inc)

set(SRC_DIR "src")
set(INC_DIR "inc")
set(SOURCES
        ${SRC_DIR}/main.cpp
        ${SRC_DIR}/spellchecker/interpreter.cpp
        ${SRC_DIR}/utils/string_utils.cpp
        ${INC_DIR}/spellchecker/interpreter.h
        ${INC_DIR}/utils/string_utils.h
        )

add_executable(spellchecker ${SOURCES})