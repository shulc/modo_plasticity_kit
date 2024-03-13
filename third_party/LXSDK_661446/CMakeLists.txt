file(GLOB LXSDK_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/common/*.cpp)

add_library(lxsdk
	${LXSDK_SOURCES}
)

target_include_directories(lxsdk PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)