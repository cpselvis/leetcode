/**
 * Single Number
 * 
 * cpselvis(cpselvis@gmail.com)
 * September 5th, 2016
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int ret = 0;
    for (int i = 0; i < nums.size(); i ++)
    {
      ret ^= nums[i];
    }
    return ret;
  }
};

int main(int argc, char **argv)
{
  int arr[7] = {1, 2, 2, 3, 3, 4, 4};
  vector<int> nums(arr + 0, arr + 7);

  Solution s;
  cout << s.singleNumber(nums) << endl;
}
