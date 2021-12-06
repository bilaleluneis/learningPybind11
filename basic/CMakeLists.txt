cmake_minimum_required(VERSION 3.20)
project(basic)

# compiler settings
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

# Ensures all generated .so files will be put under /tmp
# Make sure /tmp is part of python path of interpeter or venv by including it into site-packages as .pth file
# In run configs for any C/C++ executable add:
# PYTHONHOME=/opt/Python-3.9.1;PYTHONPATH=/opt/Python-3.9.1/build/lib.linux-aarch64-3.9:/opt/Python-3.9.1/Lib:/tmp
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY /tmp)

# python paths
set(PYTHON_EXECUTABLE /opt/Python-3.9.1/python)
set(PYTHON_INCLUDE_DIRS /opt/Python-3.9.1 /opt/Python-3.9.1/Include)
set(PYTHON_LIBRARY /opt/Python-3.9.1/libpython3.9.so)
set(PYTHONHOME /opt/Python-3.9.1)
set(PYTHONPATH /opt/Python-3.9.1/build/lib.linux-aarch64-3.9 /opt/Python-3.9.1/Lib)

# include python and pybind11
include_directories(${PYTHON_INCLUDE_DIRS})
find_package(pybind11 REQUIRED)

#enable CTests
#include(CTest)
enable_testing()

# generate executable and python shared library
add_executable(arithmetic test.cpp arithmetic.cpp arithmetic.h)
target_link_libraries(arithmetic pybind11::embed)
pybind11_add_module(py_arithmetic py_arithmetic.cpp arithmetic.cpp arithmetic.h)
add_test(NAME arithmeticTest COMMAND arithmetic py_arithmetic)


