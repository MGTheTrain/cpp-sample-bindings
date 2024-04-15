#ifdef MGTT_RENDERING_TEST
#include <gtest/gtest.h>
#include <math-utils.h>

class MathOperationsTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

// Test case for MathOperations::add method
TEST_F(MathOperationsTest, AddTest) {
    int a = 5;
    int b = 3;    

    int result = Mgtt::Core::MathOperations::add(a, b);
    EXPECT_EQ(result, 8);
}

// Test case for MathOperations::subtract method
TEST_F(MathOperationsTest, SubtractTest) {
    int a = 5;
    int b = 3;

    int result = Mgtt::Core::MathOperations::subtract(a, b);
    EXPECT_EQ(result, 2); // Expect the result to be 2
}

// Test case for MathOperations::multiply method
TEST_F(MathOperationsTest, MultiplyTest) {
    int a = 5;
    int b = 3;

    int result = Mgtt::Core::MathOperations::multiply(a, b);
    EXPECT_EQ(result, 15); // Expect the result to be 15
}

// Test case for MathOperations::divide method
TEST_F(MathOperationsTest, DivideTest) {
    float a = 10.0f;
    float b = 2.0f;

    float result = Mgtt::Core::MathOperations::divide(a, b);
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
    Mgtt::Core::Circle circle(radius);

    float area = circle.getArea();
    EXPECT_FLOAT_EQ(area, M_PI * radius * radius); // Expect the area to be pi * r^2
}

// Test case for Circle::getCircumference method
TEST_F(CircleTest, GetCircumferenceTest) {
    float radius = 5.0f;
    Mgtt::Core::Circle circle(radius);

    float circumference = circle.getCircumference();
    EXPECT_FLOAT_EQ(circumference, 2 * M_PI * radius); // Expect the circumference to be 2 * pi * r
}

#endif