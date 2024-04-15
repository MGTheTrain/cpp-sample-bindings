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

namespace Mgtt::Core {
    /**
     * @brief Adds two integers.
     * @param a The first integer.
     * @param b The second integer.
     * @return The sum of a and b.
     */
    int MathOperations::add(int a, int b) {
        return a + b;
    }

    /**
     * @brief Subtracts one integer from another.
     * @param a The integer to subtract from.
     * @param b The integer to subtract.
     * @return The result of subtracting b from a.
     */
    int MathOperations::subtract(int a, int b) {
        return a - b;
    }

    /**
     * @brief Multiplies two integers.
     * @param a The first integer.
     * @param b The second integer.
     * @return The product of a and b.
     */
    int MathOperations::multiply(int a, int b) {
        return a * b;
    }

    /**
     * @brief Divides one float by another.
     * @param a The float to divide.
     * @param b The divisor.
     * @return The result of dividing a by b.
     * @throw Division by zero error if b is zero.
     */
    float MathOperations::divide(float a, float b) {
        if (b == 0) {
            throw "Division by zero error";
        }
        return a / b;
    }

    /**
     * @brief Constructs a Circle object with the given radius.
     * @param radius The radius of the circle.
     */
    Circle::Circle(float radius) {
        this->radius = radius;
    }

    /**
     * @brief Calculates the area of the circle.
     * @return The area of the circle.
     */
    float Circle::getArea() {
        return M_PI * radius * radius;
    }

    /**
     * @brief Calculates the circumference of the circle.
     * @return The circumference of the circle.
     */
    float Circle::getCircumference() {
        return 2 * M_PI * radius;
    }
}

/**
 * C++ wrapper
*/
extern "C" {
    int32_t add(int32_t a, int32_t b) {
        Mgtt::Core::MathOperations math;
        return math.add(a, b);
    }

    int32_t subtract(int32_t a, int32_t b) {
        Mgtt::Core::MathOperations math;
        return math.subtract(a, b);
    }

    int32_t multiply(int32_t a, int32_t b) {
        Mgtt::Core::MathOperations math;
        return math.multiply(a, b);
    }

    float divide(float a, float b) {
        Mgtt::Core::MathOperations math;
        try {
            return math.divide(a, b);
        } catch (const char* error) {
            throw std::runtime_error(error);
        }
    }

    void* create_circle(float radius) {
        return new Mgtt::Core::Circle(radius);
    }

    float get_area(void* circle_ptr) {
        Mgtt::Core::Circle* circle = reinterpret_cast<Mgtt::Core::Circle*>(circle_ptr);
        return circle->getArea();
    }

    float get_circumference(void* circle_ptr) {
        Mgtt::Core::Circle* circle = reinterpret_cast<Mgtt::Core::Circle*>(circle_ptr);
        return circle->getCircumference();
    }

    void delete_circle(void* circle_ptr) {
        Mgtt::Core::Circle* circle = reinterpret_cast<Mgtt::Core::Circle*>(circle_ptr);
        delete circle;
    }

}