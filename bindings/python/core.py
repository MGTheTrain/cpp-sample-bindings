import ctypes
import sys

if sys.platform.startswith('win32'):
    core_lib = ctypes.cdll.LoadLibrary('./core__wrapper.dll')
elif sys.platform.startswith('linux'):
    core_lib = ctypes.cdll.LoadLibrary('./core__wrapper.so')
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

core_lib.create_circle.restype = ctypes.c_void_p
core_lib.create_circle.argtypes = [ctypes.c_float]

core_lib.get_area.restype = ctypes.c_float
core_lib.get_area.argtypes = [ctypes.c_void_p]

core_lib.get_circumference.restype = ctypes.c_float
core_lib.get_circumference.argtypes = [ctypes.c_void_p]

core_lib.delete_circle.argtypes = [ctypes.c_void_p]

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
    circle_ptr = core_lib.create_circle(radius)

    area = core_lib.get_area(circle_ptr)
    print("Circle area:", area)

    circumference = core_lib.get_circumference(circle_ptr)
    print("Circle circumference:", circumference)

    core_lib.delete_circle(circle_ptr)

if __name__ == "__main__":
    main()
