#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <limits>
#include <deque>
#include <algorithm>
#include <sstream>
#include <set>
#include <thread>
#include <chrono>

namespace codejam
{
  typedef unsigned long long int long_int;
  std::vector<long_int> kprimes;
}

/**
 * A function that generates Prime Numbers
 * The generated prime number is stored in a lookup vector
 * kprimes
 *
 * @param x Largest number to generate prime
 * @return Void
 */
 
void allPrimesLessThan(codejam::long_int x)
{
  codejam::kprimes.clear();
  for(codejam::long_int i = 2; i < x; i++)
  {
    for(codejam::long_int j = 2;  j < i; j++)
    {
      if( i % j == 0) break;
      else if ( j >= std::sqrt(i))
      {
        codejam::kprimes.push_back(i);
        break;
      }
    }
  }
}

/**
 * A function that returns common prime factors
 *
 * @param x Input prime number
 * @return A pair of prime numbers that are factors of the input x
 */
std::pair<codejam::long_int, codejam::long_int> getfactors(codejam::long_int x)
{
  std::pair<codejam::long_int, codejam::long_int> xfactors;
  for(auto it : codejam::kprimes)
  {
    if ( x%it == 0){
      xfactors = std::make_pair(it, x/it);
      break;
    }
  }
  return xfactors;
}

/**
 * A function that returns the index of give value in a container
 *
 * @param container Deque in which to search for value
 * @param value Value to search for in the container
 * @return Index of value if it exists or -1 if does not exist
 *
 * @see Also review find function for deque library which implements this search.
 *
 */

long getIndex(std::deque<codejam::long_int> container, codejam::long_int value)
{
  for (size_t i = 0; i < container.size(); i++)
  {
    if (value == container[i])
      return i;
  }
  return -1;
}

/**
 * A function that returns a decrypted message for encrypted data
 *
 * @param N Number used to encrypt the message. Prime numbers below N are used for encryption
 * @param L Length of the message stream
 * @crypted_input Vector of input crypted message
 * @return A string with the decrypted message
 */
std::string decrypt(int N, int L, std::vector<codejam::long_int> crypted_input)
{
  std:: string decrypted_message = "";

  allPrimesLessThan(N);
  
  //[TODO] Guards and handling special cases
  if(crypted_input.size() != L )
    return decrypted_message;
  
  // Iterator for input data
  std::vector<codejam::long_int>::iterator it;
    
  std::deque<codejam::long_int> crypts;
  std::deque<codejam::long_int>::iterator crypt_it;

  // First crypt pairs
  std::pair<codejam::long_int,codejam::long_int> last_crypt_pairs = getfactors(crypted_input[0]);
  std::pair<codejam::long_int, codejam::long_int> current_crypt_pairs;
  
  
  // Iterate through second to end crypt pairs
  for(it = crypted_input.begin() + 1; it != crypted_input.end(); it++)
  {
    current_crypt_pairs = getfactors(*it);
    if (current_crypt_pairs.first == last_crypt_pairs.first ||
        current_crypt_pairs.first == last_crypt_pairs.second)
    {
         crypts.push_back(current_crypt_pairs.first);

    }
    else if (current_crypt_pairs.second == last_crypt_pairs.first ||
             current_crypt_pairs.second == last_crypt_pairs.second)
    {
        crypts.push_back(current_crypt_pairs.second);
    }
    last_crypt_pairs = current_crypt_pairs;
  }
  
  // Special Case for inserting first value of the crypt pair at the beginning
  it = crypted_input.begin();
  std::pair<codejam::long_int,codejam::long_int> begin_crypt_pairs = getfactors(*it);
  
  crypt_it = crypts.begin();
  if (begin_crypt_pairs.first != *crypt_it)
    crypts.push_front(begin_crypt_pairs.first);
  else
    crypts.push_front(begin_crypt_pairs.second);

  // Special Case for inserting second value of the crypt pair at the end,
  it = --crypted_input.end();
  std::pair<codejam::long_int,codejam::long_int> end_crypt_pairs = getfactors(*it);
  
  crypt_it = --crypts.end();
  if (end_crypt_pairs.first != *crypt_it)
    crypts.push_back(end_crypt_pairs.first);
  else
    crypts.push_back(end_crypt_pairs.second);
  
  // Alphabetize crypts
  std::deque<codejam::long_int> sorted_crypts = crypts;
  std::sort(sorted_crypts.begin(), sorted_crypts.end());
  sorted_crypts.erase( std::unique( sorted_crypts.begin(), sorted_crypts.end() ), sorted_crypts.end() );

  for (auto it1: crypts)
  {
    decrypted_message += char('A' + char(getIndex(sorted_crypts, it1)));
  }
  
  return decrypted_message;
}
