#include <pybind11/pybind11.h>

using namespace std;
namespace py = pybind11;

class MyClass{
public:
    
    int my_number = 0;
    MyClass(){}
    virtual int get_my_number(){return my_number;}    
};

class MyDerivedClass: public virtual MyClass{
public:
    MyDerivedClass(){}
};


PYBIND11_PLUGIN(pybi_oo_test){
    py::module m("pybi_oo_test", "test");
    py::class_<MyClass>(m, "MyClass")
        .def(py::init<>())
        .def("get_my_number", &MyClass::get_my_number);
    py::class_<MyDerivedClass>(m, "MyDerivedClass", py::base<MyClass>())
        .def(py::init<>());
    return m.ptr();
};
