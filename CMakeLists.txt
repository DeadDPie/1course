cmake_minimum_required(VERSION 3.0)
project(CLionProject C)

set(CMAKE_C_STANDARD 99)

add_executable(CLionProject
        hw4/BST.c
        #hw4/test.c
        )
#add_custom_command(TARGET CLionProject PRE_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy
#        ${CMAKE_SOURCE_DIR} $<TARGET_FILE_DIR:CLionProject>)