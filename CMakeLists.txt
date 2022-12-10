cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(OpenCV_DIR "C:/opencv/")
set(Boost_INCLUDE_DIRS "C:/boost_1_80_0/build/include/boost-1_80/")
set(Boost_LIBS "C:/boost_1_80_0/build/lib/")
set(OpenCV_INCLUDE_DIRS "C:/opencv/build/install/include/")
set(OpenCV_LIBS "C:/opencv/build/install/x64/mingw/lib/")

project(AddSomeNoise)

include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories( ${Boost_INCLUDE_DIRS} )

add_executable(${PROJECT_NAME} main.cpp noise.cpp noise.h)

target_link_libraries(${PROJECT_NAME} ${Boost_LIBS}libboost_program_options-mgw12-mt-x64-1_80.a)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBS}libboost_program_options-mgw12-mt-x64-1_80.a)
target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS}libopencv_world460.dll.a )