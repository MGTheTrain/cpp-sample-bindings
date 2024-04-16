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

package main

// #cgo LDFLAGS: -L. -lcore_wrapper
// #cgo CFLAGS: -I../../modules/core/include
// #include <stdlib.h>
// #include <math-utils.h>
import "C"
import (
	"fmt"
)

func main() {
	resultAdd := int(C.add(10, 5))
	fmt.Println("Addition result:", resultAdd)

	resultSubtract := int(C.subtract(10, 5))
	fmt.Println("Subtraction result:", resultSubtract)

	resultMultiply := int(C.multiply(10, 5))
	fmt.Println("Multiplication result:", resultMultiply)

	resultDivide := C.divide(10.0, 2.0)
	fmt.Println("Division result:", resultDivide)

	radius := 5.0
	area := C.getCircleArea(C.float(radius))
	fmt.Println("Circle area:", area)

	circumference := C.getCircleCircumference(C.float(radius))
	fmt.Println("Circle circumference:", circumference)
}
