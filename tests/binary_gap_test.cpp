#include "src/binary_gap.cpp"
#include <gtest/gtest.h>
#include <thread>
#include <iostream>

TEST (BinaryGapAllOnes, Test1)
{
  uint8_t b = 0b11111111;
  ASSERT_EQ(getBinaryGap(b), 0);
}


TEST (BinaryGapAllZeros, Test2)
{
  uint8_t b = 0b00000000;
  ASSERT_EQ(getBinaryGap(b), 0);
}

TEST (BinaryGap1, Test3)
{
    uint8_t b = 0b10001001;
    ASSERT_EQ(getBinaryGap(b), 3);
}

TEST (BinaryGap2, Test4)
{
    uint8_t b = 0b10000001;
    ASSERT_EQ(getBinaryGap(b), 6);
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

