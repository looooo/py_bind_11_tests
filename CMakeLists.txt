cmake_minimum_required(VERSION 2.6)
project(py_bind_11_tests)
ADD_DEFINITIONS(-std=c++11)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
SET(CMAKE_BUILD_TYPE REALEASE)

set(Python_ADDITIONAL_VERSIONS ${py})
find_package(PythonInterp ${py})
find_package(PythonLibs ${py})

include_directories( ${PYTHON_INCLUDE_DIRS})

PYTHON_ADD_MODULE(pybi_test SHARED pybi_test.cpp)
PYTHON_ADD_MODULE(pybi_oo_test SHARED pybi_oo_test.cpp)
PYTHON_ADD_MODULE(pybi_memory_problems SHARED pybi_memory_problems.cpp)

configure_file(test.py test.py COPYONLY)
