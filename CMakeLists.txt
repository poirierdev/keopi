cmake_minimum_required(VERSION 3.5)
project(keopi)

set(COMMON_INCLUDE_DIR
	${CMAKE_CURRENT_SOURCE_DIR}/include
	)

set(LINUX_INCLUDE_DIR
	${CMAKE_CURRENT_SOURCE_DIR}/include/linux
	)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
	include_directories(${LINUX_INCLUDE_DIR})
	find_package(X11 REQUIRED)
	include_directories(${X11_INCLUDE_DIR})
	link_libraries(${X11_LIBRARIES})
#elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
#	include_directories(${WINDOWS_INCLUDE_DIR})
endif()

set(COMMON_SOURCES
	main.c
	)

set(LINUX_SRC
	src/window_linux.c
	)

list(APPEND SOURCES ${COMMON_SOURCES})

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
	list(APPEND SOURCES ${LINUX_SRC})
#elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
#	list(APPEND SOURCES ${WINDOWS_SRC})
endif()

add_executable(keopi ${SOURCES})


