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
