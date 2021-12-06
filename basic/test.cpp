#include <pybind11/embed.h>
#include "arithmetic.h"

#define SUCCESS 0
#define FAILURE 1

namespace py = pybind11;


auto main() -> int {
    if(add(1, 1) != 2) return FAILURE;
    py::scoped_interpreter interpreter{};
    auto py_arithmetic = py::module_::import("py_arithmetic");
    if(py_arithmetic.attr("add")(1, 2).cast<int>() != add(1,2)) return FAILURE;
    return SUCCESS;
}

