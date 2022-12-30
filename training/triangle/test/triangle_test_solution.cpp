#include "triangle.h"

#include "gtest/gtest.h"

using namespace ::testing;

TEST(TriangleTest, testPerimeter) {
  Triangle aTriangle(5, 4, 3);

  ASSERT_EQ(15, aTriangle.getPerimeter());
}

TEST(TriangleTest, testArea) {
  Triangle aTriangle(5, 4, 3);

  ASSERT_EQ(6, aTriangle.getArea());
}

TEST(TriangleTest, testIsosceles) {
  Triangle aTriangle(3, 3, 3);

  ASSERT_TRUE(aTriangle.isIsosceles());

  Triangle anotherTriangle(5, 4, 3);

  ASSERT_FALSE(anotherTriangle.isIsosceles());
}

TEST(TriangleTest, testEquilateral) {
  Triangle aTriangle(3, 3, 3);

  ASSERT_TRUE(aTriangle.isEquilateral());

  Triangle anotherTriangle(4, 4, 3);

  ASSERT_FALSE(anotherTriangle.isEquilateral());
}
