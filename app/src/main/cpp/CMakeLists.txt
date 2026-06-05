cmake_minimum_required(VERSION 3.22.1)
project("darkinjector")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(darkinjector SHARED injector.cpp)
find_library(log-lib log)
target_link_libraries(darkinjector ${log-lib})
