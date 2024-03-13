include(FetchContent)

set(BOOST_INCLUDE_LIBRARIES asio regex thread random)
set(BOOST_ENABLE_CMAKE ON)
FetchContent_Declare(
  Boost
  URL https://github.com/boostorg/boost/releases/download/boost-1.84.0/boost-1.84.0.tar.xz
  URL_MD5 893b5203b862eb9bbd08553e24ff146a
)
FetchContent_MakeAvailable(Boost)

set(_websocketpp_git_tag 0.8.2)

set(BUILD_TESTS OFF CACHE BOOL "" FORCE)


message(STATUS "Populating websocketpp")
FetchContent_Populate(websocketpp
  GIT_REPOSITORY https://github.com/zaphoyd/websocketpp
  GIT_SHALLOW TRUE GIT_TAG ${_websocketpp_git_tag}
  SOURCE_DIR ${CMAKE_CURRENT_BINARY_DIR}/websocketpp
  UPDATE_DISCONNECTED ${THIRD_PARTY_UPDATE_DISCONNECTED}
  QUIET
)

message ("INCLUDE " ${websocketpp_SOURCE_DIR})

add_library(Websockets INTERFACE)
target_include_directories(Websockets INTERFACE ${websocketpp_SOURCE_DIR})
target_link_libraries(Websockets INTERFACE Boost::asio Boost::system Boost::thread Boost::regex Boost::random)