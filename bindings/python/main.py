// The MIT License
//
// Copyright (c) 2024 MGTheTrain
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


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