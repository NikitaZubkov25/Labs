cmake_minimum_required(VERSION 3.23)
project(lab5 C)

set(CMAKE_C_STANDARD 17)

add_subdirectory(src/includes includes)
link_libraries(includes)

#add_executable(lab4.1 "src/part 1/lab4/task1.c")
#add_executable(lab4.2 "src/part 1/lab4/task2.c")
#add_executable(lab4.3 "src/part 1/lab4/task3.c")
#add_executable(lab5.1 "src/part 1/lab5/Task1.c")
#add_executable(lab5.2 "src/part 1/lab5/Task2.c")
#add_executable(lab5.3 "src/part 1/lab5/task3.c")
#add_executable(lab6.1 "src/part 1/lab6/Task1.c")
#add_executable(lab6.2 "src/part 1/lab6/task2.c")
#add_executable(lab7.1 "src/part 1/lab7/task1.c")
#add_executable(lab8 "src/part 1/lab8/main.c")
#add_executable(lab3.1 "src/part 2/lab3/task1.c")
#add_executable(lab3.2 "src/part 2/lab3/task2.c")
add_executable(lab4 "src/part 2/lab4/lab4.c")

add_executable(2.lab1 "src/part 2/lab1/main.c")

add_executable(lab5.1 "src/part 2/lab5/task1.c")
add_executable(lab5.2 "src/part 2/lab5/task2.c")
add_executable(lab5.3 "src/part 2/lab5/task3.c")
add_executable(lab6.1 "src/part 2/lab6/task1.c")
add_executable(lab6.2 "src/part 2/lab6/task2.c")
add_executable(lab6.3 "src/part 2/lab6/task3.c")
