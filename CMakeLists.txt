cmake_minimum_required(VERSION 3.23)
project(lab5 C)

set(CMAKE_C_STANDARD 17)

include_directories(src/includes)
add_executable(lab4.1 src/lab4/task1.c)
add_executable(lab4.2 src/lab4/task2.c)
add_executable(lab4.3 src/lab4/task3.c)
add_executable(lab5.1 src/lab5/Task1.c)
add_executable(lab5.2 src/lab5/Task2.c)
add_executable(lab5.3 src/lab5/task3.c)
add_executable(lab6.1 src/lab6/Task1.c)
add_executable(lab7.1 src/lab7/task1.c)
add_executable(test test.c)

