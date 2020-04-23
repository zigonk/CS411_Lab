cmake_minimum_required(VERSION 3.5)

project(Lab01)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include_directories(include)
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
set(exec_name main)

add_executable(${exec_name} ${SOURCES})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
target_link_libraries(${exec_name} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})