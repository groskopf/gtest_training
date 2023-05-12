#include "triangle.h"

#include "gtest/gtest.h"

using namespace ::testing;

TEST(TriangleTest, testPerimeter) {
  Triangle aTriangle(5, 4, 3);

  EXPECT_EQ(12, aTriangle.getPerimeter());
}

TEST(TriangleTest, testArea) {
  Triangle aTriangle(5, 4, 3);

  EXPECT_EQ(6, aTriangle.getArea());
}

TEST(TriangleTest, testIsosceles) {
  Triangle aTriangle(4, 3, 3);

  ASSERT_TRUE(aTriangle.isIsosceles());
  ASSERT_EQ(aTriangle.getKind(), Triangle::Kind::ISOSCELES);

  Triangle anotherTriangle(5, 4, 3);

  ASSERT_FALSE(anotherTriangle.isIsosceles());

}

TEST(TriangleTest, testEquilateral) {
  Triangle aTriangle(3, 3, 3);

  ASSERT_TRUE(aTriangle.isEquilateral());
  ASSERT_EQ(aTriangle.getKind(), Triangle::Kind::EQUILATERAL);

  Triangle anotherTriangle(4, 4, 3);

  ASSERT_FALSE(anotherTriangle.isEquilateral());
}
