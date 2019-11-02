#include "src/random_generator.cpp"
#include <gtest/gtest.h>
#include <iostream>
#include <thread>

TEST (SmallVector, Test1){
  auto v = getRandomValues(1);
  ASSERT_EQ(v.size(), 1);
}

TEST (ByteReverse, Test2)
{
  uint8_t b = 0b10101101;
  std::cout << reverseByte(b);
  ASSERT_EQ(reverseByte(b), 0b10110101);
}

TEST (ByteReverse, Test3)
{
  uint8_t b = 1;
  std::cout << reverseByte(b);
  ASSERT_EQ(reverseByte(b), 128);
}

TEST (ByteReverse, Test4)
{
  uint8_t b = 0;
  std::cout << reverseByte(b);
  ASSERT_EQ(reverseByte(b), 0);
}

TEST (ByteReverse, Test5)
{
  uint8_t b = 0b11111111;
  std::cout << reverseByte(b);
  ASSERT_EQ(reverseByte(b), 0b11111111);
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
