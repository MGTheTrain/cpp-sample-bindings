#include "../include/math-utils.h"

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