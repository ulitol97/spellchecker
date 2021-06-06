cmake_minimum_required(VERSION 3.15)
project(spellchecker)
set(CMAKE_CXX_STANDARD 17)
include_directories(src inc)

set(SRC_DIR "src")
set(INC_DIR "inc")
set(SOURCES
        ${SRC_DIR}/main.cpp

        ${SRC_DIR}/spellchecker/Interpreter.cpp
        ${SRC_DIR}/utils/StringUtils.cpp
        ${SRC_DIR}/algorithms/SpellChecker.cpp
        ${SRC_DIR}/algorithms/RecursiveChecker.cpp
        ${SRC_DIR}/algorithms/MatrixChecker.cpp
        ${SRC_DIR}/algorithms/SingleRowChecker.cpp
        
        ${INC_DIR}/spellchecker/Interpreter.h
        ${INC_DIR}/utils/StringUtils.h
        ${INC_DIR}/utils/Order.h
        ${INC_DIR}/algorithms/SpellChecker.h
        ${INC_DIR}/algorithms/RecursiveChecker.h
        ${INC_DIR}/algorithms/MatrixChecker.h
        ${INC_DIR}/algorithms/SingleRowChecker.h
        inc/utils/Order.h)

add_executable(spellchecker ${SOURCES})