cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(primes)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp PrimeChecker.cpp)

add_executable(primes ${SOURCE_FILES})