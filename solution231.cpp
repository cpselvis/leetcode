/**
 * Power of Two
 * Bit maniplation.
 *
 * cpselvis(cpselvis@gmail.com)
 * Oct 9th, 2016
 */
#include<iostream>

using namespace std;

class Solution {
public:
  bool isPowerOfTwo(int n) {
    int cnt = 0;

    while (n > 0)
    {
      cnt += n & 1;
      n >>= 1;
    }
    return cnt == 1;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.isPowerOfTwo(4) << endl;
  cout << s.isPowerOfTwo(5) << endl;
}
