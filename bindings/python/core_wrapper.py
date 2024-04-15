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
