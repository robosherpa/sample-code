/*
Problem
On the Code Jam team, we enjoy sending each other pangrams, which are phrases that use each letter of the English alphabet at least once. One common example of a pangram is "the quick brown fox jumps over the lazy dog". Sometimes our pangrams contain confidential information — for example, CJ QUIZ: KNOW BEVY OF DP FLUX ALGORITHMS — so we need to keep them secure.

We looked through a cryptography textbook for a few minutes, and we learned that it is very hard to factor products of two large prime numbers, so we devised an encryption scheme codejamsed on that fact. First, we made some preparations:

We chose 26 different prime numbers, none of which is larger than some integer N.
We sorted those primes in increasing order. Then, we assigned the smallest prime to the letter A, the second smallest prime to the letter B, and so on.
Everyone on the team memorized this list.
Now, whenever we want to send a pangram as a message, we first remove all spacing to form a plaintext message. Then we write down the product of the prime for the first letter of the plaintext and the prime for the second letter of the plaintext. Then we write down the product of the primes for the second and third plaintext letters, and so on, ending with the product of the primes for the next-to-last and last plaintext letters. This new list of values is our ciphertext. The number of values is one smaller than the number of characters in the plaintext message.

For example, suppose that N = 103 and we chose to use the first 26 odd prime numbers, because we worry that it is too easy to factor even numbers. Then A = 3, B = 5, C = 7, D = 11, and so on, up to Z = 103. Also suppose that we want to encrypt the CJ QUIZ... pangram above, so our plaintext is CJQUIZKNOWBEVYOFDPFLUXALGORITHMS. Then the first value in our ciphertext is 7 (the prime for C) times 31 (the prime for J) = 217; the next value is 1891, and so on, ending with 3053.

We will give you a ciphertext message and the value of N that we used. We will not tell you which primes we used, or how to decrypt the ciphertext. Do you think you can recover the plaintext anyway?

Input
The first line of the input gives the number of test cases, T. T test cases follow; each test case consists of two lines. The first line contains two integers: N, as described above, and L, the length of the list of values in the ciphertext. The second line contains L integers: the list of values in the ciphertext.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is a string of L + 1 uppercase English alphabet letters: the plaintext.

Limits
1 ≤ T ≤ 100.
Time limit: 20 seconds per test set.
Memory limit: 1 GB.
25 ≤ L ≤ 100.
The plaintext contains each English alphabet letter at least once.

Test set 1 (Visible)
101 ≤ N ≤ 10000.

Test set 2 (Hidden)
101 ≤ N ≤ 10100.

Sample Input

10000 25
3292937 175597 18779 50429 375469 1651121 2102 3722 2376497 611683 489059 2328901 3150061 829981 421301 76409 38477 291931 730241 959821 1664197 3057407 4267589 4729181 5335543/2411*7919 7919*7919

1
10000 26
3292937 175597 18779 50429 375469 1651121 2102 3722 2376497 611683 489059 2328901 3150061 829981 421301 76409 38477 291931 730241 959821 1664197 3057407 4267589 4729181 17524747 62710561


2
103 31
217 1891 4819 2291 2987 3811 1739 2491 4717 445 65 1079 8383 5353 901 187 649 1003 697 3239 7663 291 123 779 1007 3551 1943 2117 1679 989 3053
103 32
217 961 1891 4819 2291 2987 3811 1739 2491 4717 445 65 1079 8383 5353 901 187 649 1003 697 3239 7663 291 123 779 1007 3551 1943 2117 1679 989 3053
10000 25
3292937 175597 18779 50429 375469 1651121 2102 3722 2376497 611683 489059 2328901 3150061 829981 421301 76409 38477 291931 730241 959821 1664197 3057407 4267589 4729181 5335543
10000 28
3292937 3892729 175597 7921 7921 18779 50429 375469 1651121 2102 3722 2376497 611683 489059 2328901 3150061 829981 421301 76409 38477 291931 730241 959821 1664197 3057407 4267589 4729181 5335543


Case #1: SUUUUUUUUUUUUUUUUUUBBBDERMATOGLYPHICFJKNQVWXZZZZZZ
         ZUUUUUUUUUUUUUUUUUUBBBDERMATOGLYPHICFJKNQVWXZZZZZZZ

*/


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

long getIndex(std::deque<codejam::long_int> container, codejam::long_int value)
{
  for (size_t i = 0; i < container.size(); i++)
  {
    if (value == container[i])
      return i;
  }
  return -1;
}

int main()
{
  int numtestcase;
  std::cout << "Solving the Cryptopangrams Challenge in CodeJam" << std::endl;
  std::cout << "A sample example is given below" << std::endl;
  std::cout << "1               // Number of test cases" << std ::endl;
  std::cout << "10000 26        // 10000 N prime numbers less than N; 26 L number of letters in the crypto message " << std::endl;
  std::cout << "3292937 175597 18779 50429 375469 1651121 2102 3722 2376497 611683 489059 2328901 3150061 829981 421301 76409 38477 291931 730241 959821 1664197 3057407 4267589 4729181 17524747 62710561" << std::endl;
  std::cout << "Please enter number of test cases:" << std::endl;
  std::cin >> numtestcase;
  
  int N;
  int L;
    
  for (int t=1; t<=numtestcase; t++)
  {
    std::cout << "Please enter value of N and L" << std::endl;
    std::cin>>N;
    std::cin>>L;

    allPrimesLessThan(N);
    std::vector<codejam::long_int> input;

    for (int l=1; l<=L; l++)
    {
      codejam::long_int number;
      std::cin>> number;
      input.push_back(number);
    }
    
  allPrimesLessThan(N);
  std::vector<codejam::long_int>::iterator it;
    
  std::deque<codejam::long_int> crypts;
  std::deque<codejam::long_int>::iterator crypt_it;

  // First crypt pairs
  std::pair<codejam::long_int,codejam::long_int> last_crypt_pairs = getfactors(input[0]);
  std::pair<codejam::long_int, codejam::long_int> current_crypt_pairs;
  
  
  // Iterate through second to end crypt pairs
  for(it = input.begin() + 1; it != input.end(); it++)
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
  it = input.begin();
  std::pair<codejam::long_int,codejam::long_int> begin_crypt_pairs = getfactors(*it);
  
  crypt_it = crypts.begin();
  if (begin_crypt_pairs.first != *crypt_it)
    crypts.push_front(begin_crypt_pairs.first);
  else
    crypts.push_front(begin_crypt_pairs.second);

  // Special Case for inserting second value of the crypt pair at the end,
  it = input.end() - 1;
  std::pair<codejam::long_int,codejam::long_int> end_crypt_pairs = getfactors(*it);
  
  crypt_it = crypts.end() - 1;
  if (end_crypt_pairs.first != *crypt_it)
    crypts.push_back(end_crypt_pairs.first);
  else
    crypts.push_back(end_crypt_pairs.second);
  
  // Sorting Crypts to Alphabetize them
  std::deque<codejam::long_int> sorted_crypts = crypts;
  std::sort(sorted_crypts.begin(), sorted_crypts.end());
  sorted_crypts.erase( std::unique( sorted_crypts.begin(), sorted_crypts.end() ), sorted_crypts.end() );

    std::cout<<"\n";
   for (auto it: sorted_crypts)
   {
     std::cout<< char('A' + char(getIndex(sorted_crypts, it))) <<" = " << it << std::endl;
   }
                      
  std::cout<<"\nCase #" << t << ": ";
  
  for (auto it1: crypts)
  {
    std::cout << char('A' + char(getIndex(sorted_crypts, it1)));
  }

  }
}



