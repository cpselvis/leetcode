/**
 * Sqrt(x)
 *
 * cpselvis(cpselvis@gmail.com)
 * September 21th, 2016
 */
#include<iostream>

using namespace std;

class Solution {
public:
  int mySqrt(int x) {
    long lower = 0, upper = x;

    while (lower <= upper)
    {
      long mid = (lower + upper) >> 1;
      if (mid * mid <= x && x < (mid + 1) * (mid + 1))
      {
	return mid;
      }
      else if (x < mid * mid)
      {
	upper = mid - 1;
      }
      else
      {
	lower = mid + 1;
      }
    }
    return -1;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.mySqrt(2147395599) << endl;
}
