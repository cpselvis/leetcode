/**
 * Plus One
 *
 * cpselvis (cpselvis@gmail.com)
 * August 27th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    int i = digits.size() - 1, carry = 1;

    while (i >= 0)
    {
      int sum = digits[i] + carry;
      if (sum >= 10)
      {
	digits[i] = sum - 10;
	carry = 1;
      }
      else
      {
	digits[i] = sum;
	carry = 0;
      }
      i --;
    }
    if (carry == 1)
    {
      digits.insert(digits.begin(), 1);
    }

    return digits;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  int arr[5] = {9, 9, 9, 9, 9};
  vector<int> vec(arr + 0, arr + 5);
  vector<int> ret = s.plusOne(vec);

  for (auto i : ret)
  {
    cout << i << endl;
  }  
}
