/**
 * Pow(x, n)
 *
 * cpselvis (cpselvis@gmail.com)
 * September 21th, 2016
 */
#include<iostream>

using namespace std;

class Solution {
public:
  double myPow(double x, int n) {
    long k = n;
    if (k == 0)
    {
      return 1;
    }

    double ret = 1;
    if (k < 0)
    {
      x = 1 / x;
      k = -k;
    }

    while (k > 0)
    {
      if (k % 2 == 1)
      {
	ret *= x;
      }
      x *= x;
      k /= 2;
    }
    return ret;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.myPow(2, 0) << endl;
  cout << s.myPow(2, 2) << endl;
  cout << s.myPow(2, -2) << endl;
  cout << s.myPow(8.88023, 3) << endl;
}
