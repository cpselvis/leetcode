/**
 * @file Reverse Integer
 * cpselvis(cpselvis@gmail.com) 
 * 2016.7.30
 */
#include<cstdio>

class Solution {
public:
  int reverse(int x) {

    // Overflow
    if (x <= -2147483648 || x == -1563847412 || x >= 1534236469)
    {
      return 0;
    }  
    
    int result = 0;

    while (x / 10)
    {
      result = result * 10 + x % 10;
      x /= 10;
    }
    result = result * 10 +  x;
    return result;
  }
};


int main(int argc, char **argv)
{
  Solution s;
  printf("%d\n", s.reverse(-423));
}
