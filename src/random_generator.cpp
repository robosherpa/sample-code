#include <iostream>
#include <vector>


std::vector<int> getRandomValues(int n){
  std::vector<int> result;
  for(int i = 0; i < n; i++)
  {
    result.push_back(std::rand()%n);
  }
  return result;
}

uint8_t reverseByte(uint8_t data){
  uint8_t result;
  for(int i = 0; i < 8; i++)
  {
    result = result << 1;
    result += data % 2;
    data = data >> 1;
  }
  return result;
}

