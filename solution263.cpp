/**
 * Ugly Number
 *
 * cpselvis (cpselvis@gmail.com)
 * September 16th, 2016
 */
#include<iostream>

using namespace std;

class Solution {
public:
  bool isUgly(int num) {
    int arr[3] = {2, 3, 5};

    if (num <= 0)
    {
      return false;
    }
    
    for (auto i : arr)
    {
      while (num % i == 0)
      {
	num /= i;
      }
    }
    return num == 1;
  }
};

int main(int argc, char **argv)
{
  Solution s;

  cout << s.isUgly(6) << endl;
  cout << s.isUgly(8) << endl;
  cout << s.isUgly(14) << endl;
}
