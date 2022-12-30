#include "triangle.h"

#include "gtest/gtest.h"

using namespace ::testing;

TEST(TriangleTest, DISABLED_testPerimeter) {
  Triangle aTriangle(5, 4, 3);

  ASSERT_EQ(15, aTriangle.getPerimeter());
}
