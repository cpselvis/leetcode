/**
 * @file Palindrome number
 * cpselvis(cpselvis@gmail.com)
 * 2016.7.30
 */
#include<iostream>

using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    // negative integers
    if( x < 0 )
    {
      return false;
    }
    if( x == 0 )
    {
      return true;
    }

    if (x == reverse(x))
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  int reverse(int x)
  {
    int result = 0;

    // Overflow situation
    if (x < INT_MIN || x > INT_MAX )
    {
      return 0;
    }

    while (x / 10 > 0)
    {
      result = result * 10 + x % 10;
      x /= 10;
    }
    result = result * 10 + x;
    return result;
  }

};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.isPalindrome(1534334351) << endl;
}
