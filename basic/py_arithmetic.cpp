#include <pybind11/pybind11.h>
#include "arithmetic.h"

namespace py = pybind11;

PYBIND11_MODULE(py_arithmetic, m) {
    m.def("add", &add, "function which adds two ints");
}


