/**
 *  Move Zeroes 
 *
 * cpselvis (cpselvis@gmail.com)
 * September 28th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int n = nums.size();

    int j = 0;
    for (int i = 0; i < n; i ++)
    {
      if (nums[i] != 0)
      {
        nums[j ++] = nums[i];
      }
    }

    for (; j < n; j ++)
    {
      nums[j] = 0;
    }
  }
};

int main(int argc, char **argv)
{
  Solution s;
  vector<int> vec = {0, 1, 0, 3, 12};
  s.moveZeroes(vec);
  for (auto i : vec)
  {
    cout << i << endl;
  }
}
