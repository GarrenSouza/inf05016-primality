cmake_minimum_required(VERSION 3.16)

project(primality)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(prime_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/prime.cpp")

add_executable(primality_test ${prime_SOURCES})
set_property(TARGET primality_test PROPERTY CXX_STANDARD 20)
target_include_directories(primality_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(primality_test gmp gmpxx)
