cmake_minimum_required(VERSION 3.12)
project(plasticity_kit CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories (third_party/thread/include)
include_directories (third_party/config/include)
include_directories (third_party/system/include)
include_directories (third_party/assert/include)
include_directories (third_party/static_assert/include)
include_directories (third_party/core/include)
include_directories (third_party/type_traits/include)
include_directories (third_party/asio/include)
include_directories (third_party/throw_exception/include)
include_directories (third_party/align/include)
include_directories (third_party/date_time/include)
include_directories (third_party/smart_ptr/include)
include_directories (third_party/utility/include)
include_directories (third_party/numeric_conversion/include)
include_directories (third_party/mpl/include)
include_directories (third_party/preprocessor/include)
include_directories (third_party/websocketpp)


add_executable(${PROJECT_NAME} src/main.cpp)

