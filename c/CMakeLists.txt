cmake_minimum_required(VERSION 3.0)
project(testc)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp teamcity_cppunit.cpp  teamcity_cppunit.h  teamcity_messages.cpp  teamcity_messages.h)
add_executable(testc ${SOURCE_FILES})

target_link_libraries(testc cppunit)