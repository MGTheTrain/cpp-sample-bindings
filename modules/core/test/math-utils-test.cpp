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

  int result = add(a, b);
  EXPECT_EQ(result, 8);
}

// Test case for MathOperations::subtract method
TEST_F(MathOperationsTest, SubtractTest) {
  int a = 5;
  int b = 3;

  int result = subtract(a, b);
  EXPECT_EQ(result, 2);  // Expect the result to be 2
}

// Test case for MathOperations::multiply method
TEST_F(MathOperationsTest, MultiplyTest) {
  int a = 5;
  int b = 3;

  int result = multiply(a, b);
  EXPECT_EQ(result, 15);  // Expect the result to be 15
}

// Test case for MathOperations::divide method
TEST_F(MathOperationsTest, DivideTest) {
  float a = 10.0f;
  float b = 2.0f;

  float result = divide(a, b);
  EXPECT_FLOAT_EQ(result, 5.0f);  // Expect the result to be 5.0
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

  float area = getCircleArea(radius);
  EXPECT_FLOAT_EQ(area, expectedArea);  // Expect the area to be pi * r^2
}

// Test case for Circle::getCircumference method
TEST_F(CircleTest, GetCircumferenceTest) {
  float radius = 5.0f;
  float expectedCircumference = 2 * M_PI * radius;

  float circumference = getCircleCircumference(radius);
  EXPECT_FLOAT_EQ(
      circumference,
      expectedCircumference);  // Expect the circumference to be 2 * pi * r
}

#endif  // End of MGTT_CORE_TEST