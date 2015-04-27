CMAKE_MINIMUM_REQUIRED( VERSION 2.6 )

PROJECT( libevpp CXX C )

SET( SRCS
     "src/EventLoop.cpp" )

SET( CMAKE_CXX_FLAGS
     "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -std=c++1y" )

INCLUDE_DIRECTORIES( "${PROJECT_SOURCE_DIR}/include" )

ADD_LIBRARY( evpp STATIC ${SRCS} )

