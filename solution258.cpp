/**
 * Add Digits
 *
 * cpselvis(cpselvis@gmail.com)
 * September 27th, 2016
 */
#include<iostream>

using namespace std;

class Solution {
public:
  int addDigits(int num) {
    while (num >= 10)
    {
      int sum = 0;
      while (num)
      {
	sum += num % 10;
	num /= 10;
      }
      num = sum;
    }
    return num;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.addDigits(38) << endl;
}
