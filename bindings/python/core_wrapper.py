import ctypes

class CoreWrapper:
    """
    A wrapper class for a core library implemented in C/C++ using ctypes.

    Attributes:
        core_lib (CDLL): The loaded core library.
    """

    def __init__(self, path: str):
        """
        Initialize the CoreWrapper instance.

        Args:
            path (str): The path to the core library.
        """
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

    def add(self, a: int, b: int) -> int:
        """
        Add two integers using the core library.

        Args:
            a (int): The first integer.
            b (int): The second integer.

        Returns:
            int: The result of the addition.
        """
        return self.core_lib.add(a, b)

    def subtract(self, a: int, b: int) -> int:
        """
        Subtract two integers using the core library.

        Args:
            a (int): The first integer.
            b (int): The second integer.

        Returns:
            int: The result of the subtraction.
        """
        return self.core_lib.subtract(a, b)

    def multiply(self, a: int, b: int) -> int:
        """
        Multiply two integers using the core library.

        Args:
            a (int): The first integer.
            b (int): The second integer.

        Returns:
            int: The result of the multiplication.
        """
        return self.core_lib.multiply(a, b)

    def divide(self, a: float, b: float) -> float:
        """
        Divide two floats using the core library.

        Args:
            a (float): The numerator.
            b (float): The denominator.

        Returns:
            float: The result of the division.
        """
        return self.core_lib.divide(a, b)

    def get_circle_area(self, radius: float) -> float:
        """
        Calculate the area of a circle using the core library.

        Args:
            radius (float): The radius of the circle.

        Returns:
            float: The area of the circle.
        """
        return self.core_lib.getCircleArea(radius)

    def get_circle_circumference(self, radius: float) -> float:
        """
        Calculate the circumference of a circle using the core library.

        Args:
            radius (float): The radius of the circle.

        Returns:
            float: The circumference of the circle.
        """
        return self.core_lib.getCircleCircumference(radius)

