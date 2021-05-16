CMAKE_MINIMUM_REQUIRED(VERSION 3.1.3)
PROJECT(openCVDemo)

option(ENABLE_TESTS "Enable Tests" true)

#编译tests目录下的测试demo,一个cpp文件一个demo
if (NOT IOS)
    #测试程序
    if(ENABLE_TESTS)
        add_subdirectory(tests)
    endif()
endif ()
