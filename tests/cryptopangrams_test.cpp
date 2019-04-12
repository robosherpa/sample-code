#include "src/cryptopangrams.cpp"
#include <gtest/gtest.h>

TEST (CryptoPangrams, InvalidSizeL){
  std :: string message;
  int N = 10000;
  int L = 25;
  std::vector<codejam::long_int> cryptedMessage{
    3292937, 175597, 18779, 50429, 375469, 1651121, 2102, 3722,
    2376497, 611683, 489059,2328901, 3150061, 829981, 421301,
    76409, 38477, 291931, 730241, 959821, 1664197, 3057407,
    4267589, 4729181, 17524747, 62710561};
  message = decrypt(N, L, cryptedMessage);
  std::cout << "Decrypted Message: " << message << std::endl;
  ASSERT_EQ(message, "");
}


TEST (CryptoPangrams, SimpleStrings1){
  std :: string message;
  int N = 10000;
  int L = 26;
  std::vector<codejam::long_int> cryptedMessage{
    3292937, 175597, 18779, 50429, 375469, 1651121, 2102, 3722,
    2376497, 611683, 489059,2328901, 3150061, 829981, 421301,
    76409, 38477, 291931, 730241, 959821, 1664197, 3057407,
    4267589, 4729181, 17524747, 62710561};
  message = decrypt(N, L, cryptedMessage);
  std::cout << "Decrypted Message: " << message << std::endl;
  ASSERT_EQ(message, "SUBDERMATOGLYPHICFJKNQVWXZZ");
}

TEST (CryptoPangrams, SimpleStrings2){
  std :: string message;
  int N = 103;
  int L = 31;
  std::vector<codejam::long_int> cryptedMessage{
    217, 1891, 4819, 2291, 2987, 3811, 1739, 2491, 4717, 445,
    65, 1079, 8383, 5353, 901, 187, 649, 1003, 697, 3239, 7663,
    291, 123, 779, 1007, 3551, 1943, 2117, 1679, 989, 3053};
  message = decrypt(N, L, cryptedMessage);
  std::cout << "Decrypted Message: " << message << std::endl;
  ASSERT_EQ(message, "CJQUIZKNOWBEVYOFDPFLUXALGORITHMS");
}

//[TODO] Generate Complex Test Cases with large datasets

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}