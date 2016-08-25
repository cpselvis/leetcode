/**
 * Divide Two Integers
 * 
 * cpselvis (cpselvis@gmail.com)
 * August 25th, 2016
 */
#include<iostream>
#include<cmath>

using namespace std;

class Solution {
public:
  int divide(int dividend, int divisor) {
    if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
    {
      return INT_MAX;
    }

    int sign = ((dividend > 0) ^ (divisor > 0 )) ? -1 : 1;  // ^ in C++ means XOR, when condition returns same result , then value is 0, or value is 1.
    long long int dvd = labs(dividend);                     // abs is only used for int type, when input is long int, use labs, float, use fabs.
    long long int dvr = labs(divisor);

    int ret = 0;
    while (dvd >= dvr)
    {
      int multiple = 1;
      long long int tmp = dvr;
      while (dvd >= (tmp << 1))
      {
	tmp <<= 1;
	multiple <<= 1;
      }
      dvd -= tmp;
      ret += multiple;
    }
    return  ret * sign;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.divide(6, 2) << endl;
  cout << s.divide(-1, 1) << endl;
  cout << s.divide(-2147483648, 1) << endl;
}
