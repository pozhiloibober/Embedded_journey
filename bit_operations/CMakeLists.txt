cmake_minimum_required(VERSION 3.14)
project(bit_operations LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(bit_operations
    main.c
    bitops.c
    bitops.h
    gpio.h
    gpio.c
)
