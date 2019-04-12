#include "src/topK.cpp"
#include <gtest/gtest.h>


TEST (SimpleIntVector, NullInputTest){
  std::vector<int> data{};
  int topK = 3;
  auto resultVector = getTopK(data, topK);
  ASSERT_EQ(resultVector.size(), 0);
}

TEST (SimpleIntVector, KLargerThanSizeOfData){
  std::vector<int> data{1, 2, 3, 7, 3, 3, 2, 2, 3, 1};
  int topK = 11;
  auto resultVector = getTopK(data, topK);
  ASSERT_EQ(resultVector.size(), 0);
}

TEST (SimpleIntVector, Sample1){
  std::vector<int> data{1, 2, 3, 7, 3, 3, 2, 2, 3, 1};
  int topK = 3;
  auto resultVector = getTopK(data, topK);
  ASSERT_EQ(resultVector[0], 3);
  ASSERT_EQ(resultVector[1], 2);
  ASSERT_EQ(resultVector[2], 1);
}

TEST (SimpleIntVector, Sample2){
  std::vector<int> data{1, 2, 3, 7, 7, 7, 7, 7, 3, 3, 2, 2, 3, 1};
  int topK = 7;
  auto resultVector = getTopK(data, topK);
  ASSERT_EQ(resultVector[0], 7);
  ASSERT_EQ(resultVector[1], 3);
  ASSERT_EQ(resultVector[2], 2);
  ASSERT_EQ(resultVector[3], 1);
}

TEST (SimpleIntVector, SampleCharacters){
  std::vector<char> data{'p','a','n','o','r','a','m','a','a','n','d','m','e','m','o','r','a','n','d','u','m'};
  int topK = 2;
  auto resultVector = getTopK(data, topK);
  ASSERT_EQ(resultVector[0], 'a');
  ASSERT_EQ(resultVector[1], 'm');
}

// Expect ascending order for equal frequency
TEST (SimpleIntVector, SampleNonRepeatingCharacters){
  std::vector<char> data{'c','d','e','l','m','o','x','y','z','a','b'};
  int topK = 2;
  auto resultVector = getTopK(data, topK);
  ASSERT_EQ(resultVector[0], 'a');
  ASSERT_EQ(resultVector[1], 'b');
}


TEST (SimpleIntVector, SampleStrings){
  std::vector<std::string> data{"There", "are", "many", "many", "apples", "in", "the", "tree",
                                "but", "the", "apples", "are", "really", "really", "small",
                                "than", "the", "apples", "from", "last", "year"};
  int topK = 2;
  auto resultVector = getTopK(data, topK);
  ASSERT_EQ(resultVector[0], "apples");
  ASSERT_EQ(resultVector[1], "the");
}

int main(int argc, char** argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}