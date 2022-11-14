cmake_minimum_required(VERSION 3.23)
project(SentenceGen C)

set(CMAKE_C_STANDARD 11)

add_executable(SentenceGen
        main.c struct.c struct.h file.c file.h tag.c tag.h menu.c menu.h)
