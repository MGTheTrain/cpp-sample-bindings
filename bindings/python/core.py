import ctypes
import sys
import os

# Refer to: https://realpython.com/python-bindings-overview/#how-its-installed

dir_path = os.path.dirname(os.path.realpath(__file__))

lib_name=""
if sys.platform.startswith('win32'):
    lib_name=os.path.join(dir_path, './core_wrapper.dll') # issues with DLL's -> prefer dev container on WIndows or unix systems 
    core_lib = ctypes.cdll.LoadLibrary(lib_name)
elif sys.platform.startswith('linux'):
    lib_name=os.path.join(dir_path, './libcore_wrapper.so')
    core_lib = ctypes.cdll.LoadLibrary(lib_name)
else:
    raise OSError("Unsupported platform")

core_lib.add.restype = ctypes.c_int32
core_lib.add.argtypes = [ctypes.c_int32, ctypes.c_int32]

core_lib.subtract.restype = ctypes.c_int32
core_lib.subtract.argtypes = [ctypes.c_int32, ctypes.c_int32]

core_lib.multiply.restype = ctypes.c_int32
core_lib.multiply.argtypes = [ctypes.c_int32, ctypes.c_int32]

core_lib.divide.restype = ctypes.c_float
core_lib.divide.argtypes = [ctypes.c_float, ctypes.c_float]

core_lib.getCircleArea.restype = ctypes.c_float
core_lib.getCircleArea.argtypes = [ctypes.c_float]

core_lib.getCircleCircumference.restype = ctypes.c_float
core_lib.getCircleCircumference.argtypes = [ctypes.c_float]

def main():
    result_add = core_lib.add(10, 5)
    print("Addition result:", result_add)

    result_subtract = core_lib.subtract(10, 5)
    print("Subtraction result:", result_subtract)

    result_multiply = core_lib.multiply(10, 5)
    print("Multiplication result:", result_multiply)

    result_divide = core_lib.divide(10.0, 2.0)
    print("Division result:", result_divide)

    radius = 5.0

    area = core_lib.getCircleArea(radius)
    print("Circle area:", area)

    circumference = core_lib.getCircleCircumference(radius)
    print("Circle circumference:", circumference)

if __name__ == "__main__":
    main()
