/**
 * Count Primes
 * The Sieve of Eratosthenes algorithm.
   Input: an integer n > 1
 
   Let A be an array of Boolean values, indexed by integers 2 to n,
   initially all set to true.
 
   for i = 2, 3, 4, ..., not exceeding √n:
     if A[i] is true:
       for j = i2, i2+i, i2+2i, i2+3i, ..., not exceeding n :
         A[j] := false
 
   Output: all i such that A[i] is true.
 *  
 * cpselvis(cpselvis@gmail.com)
 * September 6th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  int countPrimes(int n) {
    vector<bool> isPrime(n, true);
    int ret = 0;

    for (int i = 2; i * i <= n; i ++)
    {
      if (isPrime[i])
      {
	for (int j = i * i; j <= n; j += i)
	{
	  isPrime[j] = false;
	}
      }	
    }

    for (int i = 2; i < n; i ++)
    {
      if (isPrime[i])
      {
	ret ++;
      }
    }
    
    return ret;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.countPrimes(10) << endl;
  cout << s.countPrimes(100) << endl;
  cout << s.countPrimes(999983) << endl;
}
