import sys

sys.path.insert(0, "build/")

import pybi_test

class subclass(pybi_test.test_class):
    def foo(self):
        return 3


obj = pybi_test.test_class()
sub_obj = subclass()

print(sub_obj.test_foo())
print(obj.test_foo())