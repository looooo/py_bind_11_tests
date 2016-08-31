cmake_minimum_required(VERSION 2.6)
project(py_bind_11_tests)
ADD_DEFINITIONS(-std=c++11)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
SET(CMAKE_BUILD_TYPE REALEASE)

set(Python_ADDITIONAL_VERSIONS ${py})
find_package(PythonInterp ${py})
find_package(PythonLibs ${py})

include_directories( ${PYTHON_INCLUDE_DIRS})

add_library(nothing nothing.cpp)

PYTHON_ADD_MODULE(pybi_test SHARED pybi_test.cpp)
PYTHON_ADD_MODULE(pybi_oo_test SHARED pybi_oo_test.cpp)
PYTHON_ADD_MODULE(pybi_memory_problems SHARED pybi_memory_problems.cpp)
PYTHON_ADD_MODULE(pybi_shared_pointer SHARED pybi_shared_pointer.cpp)


target_link_libraries(pybi_memory_problems nothing)

configure_file(test.py test.py COPYONLY)
configure_file(test_shared.py test_shared.py COPYONLY)
