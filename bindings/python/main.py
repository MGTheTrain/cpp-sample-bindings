import argparse
import os
from core_wrapper import CoreWrapper

def main(path):
    abs_path=os.path.realpath(path)
    wrapper = CoreWrapper(abs_path)

    result_add = wrapper.add(10, 5)
    print("Addition result:", result_add)

    result_subtract = wrapper.subtract(10, 5)
    print("Subtraction result:", result_subtract)

    result_multiply = wrapper.multiply(10, 5)
    print("Multiplication result:", result_multiply)

    result_divide = wrapper.divide(10.0, 2.0)
    print("Division result:", result_divide)

    radius = 5.0

    area = wrapper.get_circle_area(radius)
    print("Circle area:", area)

    circumference = wrapper.get_circle_circumference(radius)
    print("Circle circumference:", circumference)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Process some integers.')
    parser.add_argument('--path', type=str, help='Path to the core wrapper library')
    args = parser.parse_args()

    if not args.path:
        parser.error('Please provide the path to the core wrapper library using --path')

    main(args.path)

# 0. Copy on unix systems the libcore_wrapper.so to a desired destination folder
# 1. Run `python main.py --path <path to libcore_wrapper.so>`