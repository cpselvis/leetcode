/**
 * Permutations
 * Backtack algorithm.
 * 
 * cpselvis(cpselvis@gmail.com)
 * August 31th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  vector<vector<int> > permute(vector<int>& nums) {
    vector<vector<int> > ret;
    backtack(ret, nums, 0);
    return ret;
  }
  void backtack(vector<vector<int> > &ret, vector<int> &nums, int index)
  {
    if (index == nums.size())
    {
      ret.push_back(nums);
    }
    else
    {
      for (int i = index; i < nums.size(); i ++)
      {
	swap(nums[index], nums[i]);
	backtack(ret, nums, index + 1);
	swap(nums[index], nums[i]);
      }
    }
  }
};

int main(int argc, char **argv)
{
  int arr[3] = {1, 2, 3};
  vector<int> vec(arr + 0, arr + 3);

  Solution s;
  vector<vector<int> > ret = s.permute(vec);
  for (int i = 0; i < ret.size(); i ++)
  {
    for (int j = 0; j < ret[i].size(); j ++)
    {
      cout << ret[i][j] << " ";
    }
    cout << endl;
  }
}
