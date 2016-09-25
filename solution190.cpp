/**
 * Reverse Bits
 *
 * cpselvis(cpselvis@gmail.com)
 * September 25th, 2016
 */
#include<iostream>

using namespace std;

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0;

    for (int i = 0; i < 32; i ++)
    {
      ret = (ret << 1) + (n & 1);
      n >>= 1;
    }
    return ret;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.reverseBits(43261596) << endl;
}
