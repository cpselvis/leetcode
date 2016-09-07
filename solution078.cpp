/**
 * Subsets
 *
 * cpselvis(cpselvis@gmail.com)
 * September 7th, 2016
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  vector<vector<int> > subsets(vector<int>& nums) {
    vector<vector<int> > ret;
    vector<int> sub;
    
    backtack(nums, sub, ret, 0);
    return ret;
  }

  void backtack(vector<int> &nums, vector<int> &sub,  vector<vector<int> > &ret, int index)
  {
    ret.push_back(sub);
    for (int i = index; i < nums.size(); i ++)
    {
      sub.push_back(nums[i]);
      backtack(nums, sub, ret, i + 1);
      sub.pop_back();
    }
  }
};

int main(int argc, char **argv)
{
  int arr[3] = {1, 2, 3};
  vector<int> nums(arr + 0, arr + 3);
  Solution s;
  vector<vector<int> > ret = s.subsets(nums);
  for (int i = 0; i < ret.size(); i ++)
  {
    cout << "i=" << i<< endl;
    for (int j = 0; j < ret[i].size(); j ++)
    {
      cout << ret[i][j] << endl;
    }
    cout << "end" << endl;
  }
}
