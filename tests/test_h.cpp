#include <gtest/gtest.h>
#include "../include/functions.h"

TEST(TestConvert, HandleConvert) {
  EXPECT_EQ(convertToUAH(20, 40), 800);
}