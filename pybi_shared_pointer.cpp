#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <vector>

namespace py = pybind11;

PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);

struct a_class{};
void foo(std::vector<std::shared_ptr<a_class>> in){};

PYBIND11_PLUGIN(pybi_shared_pointer){
    py::module m("pybi_shared_pointer", "test");
    py::class_<a_class> (m, "a_class").def(py::init<>());
    m.def("foo", &foo);
    return m.ptr();
};
