/**
 * Maximum Subarray
 * Greedy algorithm.
 *
 * cpselvis(cpselvis@gmail.com)
 * September 13th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    if (nums.size() == 0)
    {
      return 0;
    }
    int ret = nums[0];

    int largest = nums[0];

    for (int i = 1; i < nums.size(); i ++)
    {
      if (largest > 0)
      {
        largest += nums[i];
      }
      else
      {
	largest = nums[i];
      }
      ret = max(ret, largest);
    }
    return ret;
  }
};

int main(int argc, char **argv)
{
  int arr[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  vector<int> nums(arr + 0, arr + 9);

  Solution s;
  cout << s.maxSubArray(nums) << endl;
}
