cmake_minimum_required(VERSION 3.10.2)

project("darkinjector")

add_library(
             darkinjector
             SHARED
             injector.cpp )

find_library(
              log-lib
              log )

target_link_libraries(
                        darkinjector
                        ${log-lib} )
