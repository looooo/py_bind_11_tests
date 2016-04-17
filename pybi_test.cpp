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


class A{
public:
    A(){};
};
class B{
private:
    vector<A*> A_objects;
public:
    B(){
        for (int i=0; i < 10; i++){
            A* myAobjet = new A();
            this->A_objects.push_back(myAobjet);
        }
    }
    vector<A*> get_all(){return this->A_objects;}
};

class C{
private:
    vector<B*> B_objects;
public:
    C(){
        for (int i=0; i < 10; i++){
            B* myBobjet = new B();
            this->B_objects.push_back(myBobjet);
        }
    }
    vector<B*> get_all(){return this->B_objects;}
};

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
        .def("test_foo",[](py_test_class& test){return test.test_foo();});
        
    py::class_<A>(m, "A");
    py::class_<B>(m, "B")
        .def(py::init<>())
        .def_property_readonly("A_objects", &B::get_all);
    py::class_<C>(m, "C")
        .def(py::init<>())
        .def_property_readonly("B_objects", &C::get_all);
    return m.ptr();
};
