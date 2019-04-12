#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

/**
 * A function that compares second values for a pair of pairs
 *
 * @param pair1 First input pair.
 * @param pair2 Second input pair.
 * @return Returns true if second value of first input pair is larger
 * than that of the second input pair
 */
template<class T>
bool sortbysecond(std::pair<T,int> pairOne, std::pair<T, int> pairTwo){
  return (pairOne.second > pairTwo.second);
}

/**
 * A function that returns topK values in a given data
 *
 * @param data Vector of data.
 * @return Returns a vector of topK repeating values in the data
 */
template<class T>
std::vector<T> getTopK(const std::vector<T>& data, int topK){
  std::vector<T> resultVector;
  resultVector.clear();
  
  // Invalid input: when data size is less than topK value
  if(data.size() < topK) return resultVector;
  
  // Sort Values and copy to resultVector
  resultVector = data;
  std::sort(resultVector.begin(), resultVector.end());
  
  // Create a Vector of pairs for each individual value in input data and its total frequency
  resultVector.erase(std::unique(resultVector.begin(), resultVector.end()), resultVector.end());
  std::vector <std::pair<T,int> > dataCounter;
  for( const auto& it : resultVector){
    dataCounter.push_back(std::make_pair(it,0));
  }
  
  // Iterate over data to count number of repetitions
  for( const auto& it : data)
  {
    for (auto& dataCounterIt : dataCounter)
    {
      if(it == dataCounterIt.first)
        dataCounterIt.second++;
    }
  }

  // Sort the pair vector in by number of repetitions (TopK)
  std::sort(dataCounter.begin(), dataCounter.end(), sortbysecond<T>);
  
  // Store topK values in resultVector and return
  resultVector.clear();
  int topCounter = 0;
  for (const auto& dataCounterIt : dataCounter)
  {
    resultVector.push_back(dataCounterIt.first);
    topCounter++;
    if(topCounter > topK) break;
  }
  
  return resultVector;
}