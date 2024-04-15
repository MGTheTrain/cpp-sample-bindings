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

#include <math-utils.h>

/**
 * @brief Adds two integers.
 * @param a The first integer.
 * @param b The second integer.
 * @return The sum of a and b.
 */
int32_t add(int32_t a, int32_t b) { return a + b; }

/**
 * @brief Subtracts one integer from another.
 * @param a The integer to subtract from.
 * @param b The integer to subtract.
 * @return The result of subtracting b from a.
 */
int32_t subtract(int32_t a, int32_t b) { return a - b; }

/**
 * @brief Multiplies two integers.
 * @param a The first integer.
 * @param b The second integer.
 * @return The product of a and b.
 */
int32_t multiply(int32_t a, int32_t b) { return a * b; }

/**
 * @brief Divides one float by another.
 * @param a The float to divide.
 * @param b The divisor.
 * @return The result of dividing a by b.
 * @throw Division by zero error if b is zero.
 */
float divide(float a, float b) { return a / b; }

/**
 * @brief Calculates the area of the circle.
 * @param radius The radius of the circle.
 * @return The area of the circle.
 */
float getCircleArea(float radius) { return M_PI * radius * radius; }

/**
 * @brief Calculates the circumference of the circle.
 * @param radius The radius of the circle
 * @return The circumference of the circle.
 */
float getCircleCircumference(float radius) { return 2 * M_PI * radius; }