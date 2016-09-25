/**
 * Number of 1 Bits
 * Bit manipulation
 *
 * cpselvis(cpselvis@gmail.com)
 * September 25th, 2016
 */
#include<iostream>

using namespace std;

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int ret = 0;

    while (n)
    {
      if (n & 1)
      {
	ret ++;
      }
      n >>= 1;
    }
    return ret;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.hammingWeight(11) << endl;
}
