cmake_minimum_required(VERSION 3.23)
project(lab5 C)

set(CMAKE_C_STANDARD 99)

include_directories(includes)
add_executable(test main.c)
add_executable(lab4.1 lab4/task1.c)
add_executable(lab4.2 lab4/task2.c)
add_executable(lab4.3 lab4/task3.c)
add_executable(lab5.1 lab5/Task1.c)
add_executable(lab5.2 lab5/Task2.c)
add_executable(lab5.3 lab5/task3.c)
add_executable(lab6.1 Lab6/Task1.c)

