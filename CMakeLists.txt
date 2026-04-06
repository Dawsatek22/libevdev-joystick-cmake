cmake_minimum_required(VERSION 3.25.1 )
project(libevdev)


set(CMAKE_CXX STANDARD 23) # the current set c++ standard

find_package(PkgConfig REQUIRED)
pkg_search_module(LIBEVDEV REQUIRED libevdev)

add_executable(event_btn event_btn.cpp)
target_include_directories(event_btn PRIVATE  ${LIBEVDEV_INCLUDE_DIRS})
target_link_libraries(event_btn PRIVATE ${LIBEVDEV_LIBRARIES})
