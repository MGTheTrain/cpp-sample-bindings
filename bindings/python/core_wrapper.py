# The MIT License
#
# Copyright (c) 2024 MGTheTrain
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

import ctypes

class CoreWrapper:
    def __init__(self, path: str):
        self.core_lib = ctypes.cdll.LoadLibrary(path)
        self.core_lib.add.restype = ctypes.c_int32
        self.core_lib.add.argtypes = [ctypes.c_int32, ctypes.c_int32]

        self.core_lib.subtract.restype = ctypes.c_int32
        self.core_lib.subtract.argtypes = [ctypes.c_int32, ctypes.c_int32]

        self.core_lib.multiply.restype = ctypes.c_int32
        self.core_lib.multiply.argtypes = [ctypes.c_int32, ctypes.c_int32]

        self.core_lib.divide.restype = ctypes.c_float
        self.core_lib.divide.argtypes = [ctypes.c_float, ctypes.c_float]

        self.core_lib.getCircleArea.restype = ctypes.c_float
        self.core_lib.getCircleArea.argtypes = [ctypes.c_float]

        self.core_lib.getCircleCircumference.restype = ctypes.c_float
        self.core_lib.getCircleCircumference.argtypes = [ctypes.c_float]

    def add(self, a, b):
        return self.core_lib.add(a, b)

    def subtract(self, a, b):
        return self.core_lib.subtract(a, b)

    def multiply(self, a, b):
        return self.core_lib.multiply(a, b)

    def divide(self, a, b):
        return self.core_lib.divide(a, b)

    def get_circle_area(self, radius):
        return self.core_lib.getCircleArea(radius)

    def get_circle_circumference(self, radius):
        return self.core_lib.getCircleCircumference(radius)
