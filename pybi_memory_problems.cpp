#include <pybind11/pybind11.h>

namespace py = pybind11;

struct TestClass{
    int nr = 0;   
};


PYBIND11_PLUGIN(pybi_memory_problems){
    py::module m("pybi_memory_problems", "test");
    py::class_<TestClass>(m, "TestClass")
        .def(py::init<>())
        .def_readwrite("nr", &TestClass::nr, "the fatal number docs");
    return m.ptr();
};
