cmake_minimum_required(VERSION 3.27)
project(plasticity_kit CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -std=c++20 -fPIC")
endif (UNIX)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)

add_subdirectory(third_party)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
)
target_link_libraries(${PROJECT_NAME} PRIVATE Websockets lxsdk)

