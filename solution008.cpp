/**
 * @file String to integer.
 * cpselvis(cpselvis@gmail.com)
 * 2016.7.30
 */
#include<iostream>
#include<ctype.h>

using namespace std;

class Solution {
public:
  int myAtoi(string str) {
    /* Filter whitespace.*/
    int i = 0;
    int sign = 1;
    unsigned long long result = 0;

    while (str[i] == ' ')
    {
      i ++;
    }

    /* Parse first non-whitespace character. */
    if (str[i] != '+' && str[i] != '-' && !isdigit(str[i]))
    {
      return 0;
    }

    if (str[i] == '+')
    {
      sign = 1;
      i ++;
    }
    else if (str[i] == '-')
    {
      sign = -1;
      i ++;
    }

    while (isdigit(str[i]))
    {
      result = result * 10 + str[i] - '0';
      i ++;
      if (result > INT_MAX)
      {
        return (sign == 1) ? INT_MAX : INT_MIN;
      }
    }
    return result * sign;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  string str = "18446744073709551617";
  cout << s.myAtoi(str) << endl;
}
