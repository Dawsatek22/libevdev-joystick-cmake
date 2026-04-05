cmake_minimum_required(VERSION 3.25.1 )
project(libevdev)


set(CMAKE_CXX STANDARD 23) # the current set c++ standard

find_package(PkgConfig REQUIRED)
pkg_search_module(LIBEVDEV REQUIRED libevdev)

add_executable(joy joytest.cpp)
add_executable(event event.cpp)
target_include_directories(joy PRIVATE  ${LIBEVDEV_INCLUDE_DIRS})
target_link_libraries(joy PRIVATE ${LIBEVDEV_LIBRARIES})

target_include_directories(event PRIVATE  ${LIBEVDEV_INCLUDE_DIRS})
target_link_libraries(event PRIVATE ${LIBEVDEV_LIBRARIES})