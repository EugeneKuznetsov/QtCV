cmake_minimum_required(VERSION 3.16)

project(QtCV)

find_package(Qt5 COMPONENTS Quick Multimedia REQUIRED)
find_package(OpenCV REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(target helloqtcv)
set(headers helloworldfilter.h helloworldfilterrunnable.h facedetector.h)
set(sources main.cpp helloworldfilter.cpp helloworldfilterrunnable.cpp facedetector.cpp)
set(resources resources.qrc)
add_executable(${target} ${sources} ${headers} ${resources})
target_link_libraries(${target} PRIVATE Qt5::Quick Qt5::Multimedia opencv_core opencv_imgproc opencv_objdetect)
