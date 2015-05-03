CMAKE_MINIMUM_REQUIRED( VERSION 2.6 )

PROJECT( libevpp CXX C )

IF( ${CMAKE_SYSTEM_NAME} MATCHES "Linux" )
	ADD_DEFINITIONS( -DOS_LINUX )
	SET( PLATFORM_SRCS "src/linux/EPollEventLoopImpl.cpp"
	                   "src/linux/EventLoop_AllocateSystemEventLoop.cpp" )
ELSEIF( ${CMAKE_SYSTEM_NAME} MATCHES "Windows" )
	ADD_DEFINITIONS( -DOS_WINDOWS )
	SET( PLATFORM_SRCS "src/windows/EventLoop_AllocateSystemEventLoop.cpp"
	                   "src/windows/Win32EventLoopImpl.cpp" )
ELSE()
	MESSAGE( FATAL_ERROR "Unknown CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}" )
ENDIF()

SET( SRCS ${PLATFORM_SRCS} 
          "src/IPAddr.cpp" )

SET( CMAKE_CXX_FLAGS
     "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -std=c++1y" )

INCLUDE_DIRECTORIES( "${PROJECT_SOURCE_DIR}/include" )

ADD_LIBRARY( evpp STATIC ${SRCS} )

SET( EXAMPLE_ECHO_SRCS "examples/echo/Echo.cpp" )

ADD_EXECUTABLE( example_echo ${EXAMPLE_ECHO_SRCS} )

TARGET_LINK_LIBRARIES( example_echo evpp )

