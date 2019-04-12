#include "src/cryptopangrams.cpp"
#include <gtest/gtest.h>

TEST (CryptoPangrams, InvalidSizeL){
  std :: string message;
  int N = 10000;
  int L = 25;
  std::vector<codejam::long_int> cryptedMessage{
    3292937, 175597, 18779, 50429, 375469, 1651121, 2102, 3722, 2376497, 611683, 489059,
    2328901, 3150061, 829981, 421301, 76409, 38477, 291931, 730241, 959821, 1664197, 3057407,
    4267589, 4729181, 17524747, 62710561};
  message = decrypt(N, L, cryptedMessage);
  std::cout << message << std::endl;
  ASSERT_EQ(message, "");
}


TEST (CryptoPangrams, SimpleStrings){
  std :: string message;
  int N = 10000;
  int L = 26;
  std::vector<codejam::long_int> cryptedMessage{
    3292937, 175597, 18779, 50429, 375469, 1651121, 2102, 3722, 2376497, 611683, 489059,
    2328901, 3150061, 829981, 421301, 76409, 38477, 291931, 730241, 959821, 1664197, 3057407,
    4267589, 4729181, 17524747, 62710561};
  message = decrypt(N, L, cryptedMessage);
  std::cout << message << std::endl;
  ASSERT_EQ(message, "SUBDERMATOGLYPHICFJKNQVWXZZ");
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}