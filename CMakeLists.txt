CMAKE_MINIMUM_REQUIRED(VERSION 3.1.3)
PROJECT(openCVDemo)

# set the directory of executable files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${opencv_test_SOURCE_DIR}/bin)

# find required opencv
find_package(OpenCV REQUIRED)
# directory of opencv headers
include_directories(${OpenCV_INCLUDE_DIRS})
# name of executable file and path of source file
add_executable(opencv_test src/opencv_test.cpp)
# directory of opencv library
link_directories(${OpenCV_LIBRARY_DIRS})
# opencv libraries
target_link_libraries(opencv_test ${OpenCV_LIBS})

#set(opencvDemo_Root ${CMAKE_CURRENT_SOURCE_DIR}/src)
#AUX_SOURCE_DIRECTORY(./src dir_sours)
#ADD_EXECUTABLE(demo ${dir_sours})

option(ENABLE_TESTS "Enable Tests" true)

#编译tests目录下的测试demo,一个cpp文件一个demo
if (NOT IOS)
    #测试程序
    if(ENABLE_TESTS)
        add_subdirectory(tests)
    endif()
endif ()
