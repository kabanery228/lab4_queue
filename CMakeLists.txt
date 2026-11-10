cmake_minimum_required(VERSION 3.30)
project(lab4_queue CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(TESTS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tests")
set(GTEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/gtest")

# Собираем gtest из твоего файла
add_library(gtest STATIC "${GTEST_DIR}/gtest-all.cc")
target_include_directories(gtest PUBLIC "${GTEST_DIR}")
find_package(Threads REQUIRED)
target_link_libraries(gtest PUBLIC Threads::Threads)

# Основное приложение
add_executable(queue 
    "${SRC_DIR}/main.cpp"
    "${SRC_DIR}/queue.h"  # Добавили заголовочные файлы
)
target_include_directories(queue PRIVATE "${SRC_DIR}")

# Тесты
add_executable(run_tests 
    "${TESTS_DIR}/test_queue.cpp"
    "${TESTS_DIR}/test_main.cpp"
    "${SRC_DIR}/queue.h"  # Добавили сюда тоже, чтобы видеть их в проекте run_tests
)
target_include_directories(run_tests PRIVATE "${SRC_DIR}")
target_link_libraries(run_tests PRIVATE gtest)