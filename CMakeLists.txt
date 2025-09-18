cmake_minimum_required(VERSION 3.15)
project(neatcounter LANGUAGES CXX)

include_directories(include)

set(CMAKE_CXX_VERSION 23)

add_executable(
    neatcounter 
    main.cpp 
    src/consoleparser.cpp include/consoleparser.h
    src/fileparser.cpp  include/fileparser.h
    src/errors.cpp include/errors.h
)
