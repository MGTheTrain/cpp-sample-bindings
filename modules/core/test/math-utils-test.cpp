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

#ifdef MGTT_CORE_TEST 

#include <gtest/gtest.h>
#include <math-utils.h>

// Test fixture for MathOperations tests
class MathOperationsTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

// Test case for MathOperations::add method
TEST_F(MathOperationsTest, AddTest) {
    int a = 5;
    int b = 3;

    Mgtt::Core::MathOperations mathOperations;
    int result = mathOperations.add(a, b);
    EXPECT_EQ(result, 8);
}

// Test case for MathOperations::subtract method
TEST_F(MathOperationsTest, SubtractTest) {
    int a = 5;
    int b = 3;

    Mgtt::Core::MathOperations mathOperations;
    int result = mathOperations.subtract(a, b);
    EXPECT_EQ(result, 2); // Expect the result to be 2
}

// Test case for MathOperations::multiply method
TEST_F(MathOperationsTest, MultiplyTest) {
    int a = 5;
    int b = 3;

    Mgtt::Core::MathOperations mathOperations;
    int result = mathOperations.multiply(a, b);
    EXPECT_EQ(result, 15); // Expect the result to be 15
}

// Test case for MathOperations::divide method
TEST_F(MathOperationsTest, DivideTest) {
    float a = 10.0f;
    float b = 2.0f;

    Mgtt::Core::MathOperations mathOperations;
    float result = mathOperations.divide(a, b);
    EXPECT_FLOAT_EQ(result, 5.0f); // Expect the result to be 5.0
}

// Test fixture for Circle tests
class CircleTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

// Test case for Circle::getArea method
TEST_F(CircleTest, GetAreaTest) {
    float radius = 5.0f;
    float expectedArea = M_PI * radius * radius;

    Mgtt::Core::Circle circle(radius);
    float area = circle.getArea();
    EXPECT_FLOAT_EQ(area, expectedArea); // Expect the area to be pi * r^2
}

// Test case for Circle::getCircumference method
TEST_F(CircleTest, GetCircumferenceTest) {
    float radius = 5.0f;
    float expectedCircumference = 2 * M_PI * radius;

    Mgtt::Core::Circle circle(radius);
    float circumference = circle.getCircumference();
    EXPECT_FLOAT_EQ(circumference, expectedCircumference); // Expect the circumference to be 2 * pi * r
}

#endif // End of MGTT_CORE_TEST