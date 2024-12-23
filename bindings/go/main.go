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
