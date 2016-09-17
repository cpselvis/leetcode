/**
 * Longest Increasing Subsequence
 *
 * cpselvis(cpselvis@gmail.com)
 * September 17th, 2016
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();

    if (n == 0)
    {
      return 0;
    }

    vector<int> dp(n, 1);
    int ret = 1;

    for (int i = 1; i < n; i ++)
    {
      for (int j = 0; j < i; j ++)
      {
	if (nums[i] > nums[j] && dp[j] + 1 > dp[i])
	{
	  dp[i] = dp[j] + 1;
	  ret = max(ret, dp[i]);
	}
      }
    }

    return ret;
  }
};

int main(int argc, char **argv)
{
  int arr[9] = {1, 3, 6, 7, 9, 4, 10, 5, 6};
  vector<int> vec(arr + 0, arr + 9);

  Solution s;
  cout << s.lengthOfLIS(vec) << endl;
}
