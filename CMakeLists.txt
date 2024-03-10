cmake_minimum_required(VERSION 3.27)
project(plasticity_kit CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)

set(libs
	thread

    # primary deps
	assert
    atomic
    bind
    chrono
    concept_check
    config
    container
    container_hash
    core
    date_time
    exception
    function
    io
    move
    optional
    predef
    preprocessor
    smart_ptr
    static_assert
    system
    throw_exception
    tuple
    type_traits
    utility
    winapi
    
    # secondary deps
    align
    integer
    ratio
    typeof
    mpl
    intrusive
    describe
    mp11
    algorithm
    lexical_cast
    numeric/conversion
    range
    tokenizer
    detail
    iterator
    conversion
    array
    variant2
    function_types
    regex
    fusion
    functional
    unordered
    random
    dynamic_bitset
    asio
)
foreach(lib IN LISTS libs)
	add_subdirectory(third_party/boost/libs/${lib})
    include_directories(third_party/boost/libs/${lib}/include)
endforeach()

add_subdirectory(third_party/websocketpp EXCLUDE_FROM_ALL)
include_directories(third_party/websocketpp)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} boost_random)

