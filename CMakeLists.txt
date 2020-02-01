cmake_minimum_required(VERSION 3.2)
project(RenameSym)
set (MY_EXE ${CMAKE_PROJECT_NAME})

if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "Build type is default defined as Release. change it by define -DCMAKE_BUILD_TYPE=Debug as param to cmake")
    set(CMAKE_BUILD_TYPE Release)
endif()

include(env/conan_build_tool.cmake)
conan_cmake_run(CONANFILE conanfile.txt
                BASIC_SETUP
                BUILD missing)

set(CMAKE_CXX_STANDARD 17)

set(MY_STATIC_LIB_1 ${MY_EXE}_1)
add_library(${MY_STATIC_LIB_1}
  src/Foo1.c
  src/Bar.cpp
  src/Foo.h
  )

set(MY_STATIC_LIB_2 ${MY_EXE}_2)
add_library(${MY_STATIC_LIB_2}
  src/Foo2.c
  src/Foo.h
  )

add_executable(${MY_EXE}
  src/Main.cpp
  src/RenameSym.cpp
  src/RenameSym.h
  )

target_link_libraries(${MY_EXE} ${MY_STATIC_LIB_2} ${MY_STATIC_LIB_1} ${CONAN_LIBS})

# Tests
set(TEST_FILES
  	src/RenameSym.cpp
  	src/RenameSym.h
	tests/RenameSymTest.cpp
	tests/Main.cpp
	)
set(TEST_NAME ${CMAKE_PROJECT_NAME}Test)

add_executable(${TEST_NAME} ${TEST_FILES})
target_link_libraries(${TEST_NAME} ${CONAN_LIBS})


install(DIRECTORY ${CMAKE_SOURCE_DIR}/env/
DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
FILES_MATCHING
PATTERN "*.*"
PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ)
#FILES ${CMAKE_SOURCE_DIR}/env DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
