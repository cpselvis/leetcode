/**
 * Integer Replacement
 *
 * cpselvis(cpselvis@gmail.com)
 * September 13th, 2016
 */
#include<iostream>

using namespace std;

class Solution {
public:
  int integerReplacement(int n) {
    return recursive(n, 0);
  }
  int recursive(int n, int steps)
  {
    if (n == 1)
    {
      return steps;
    }
    if (n % 2 == 0)
    {
      return recursive(n / 2, steps + 1);
    }
    else
    {
      return min(recursive(n + 1, steps + 1), recursive(n - 1, steps + 1));
    }
  }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.integerReplacement(8) << endl;
}
