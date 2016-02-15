#include <iostream>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/operators.h>

#include <vector>
#include <tuple>
#include <map>

#include <string.h>
#include <typeinfo>

using namespace std;
namespace py = pybind11;

class c_test_class{
public:
    c_test_class(){};
    virtual int foo(){return 2;};
    int test_foo()
    {
        return this->foo();
    }
};


class py_test_class : public c_test_class {
public:
    /* Inherit the constructors */
    using c_test_class::c_test_class;

    /* Trampoline (need one for each virtual function) */
    int foo() {
        PYBIND11_OVERLOAD(
            int,              /* Return type */
            c_test_class,     /* Parent class */
            foo               /* Name of function */
        );
    }
};

PYBIND11_PLUGIN(pybi_test){
    py::module m("pybi_test", "test");
    py::class_<py_test_class> test_class(m, "test_class");
    test_class
        .def(py::init<>())
        .def("foo", &py_test_class::foo)
        .def("test_foo",[](py_test_class &c){return c.test_foo();});
    return m.ptr();
};
